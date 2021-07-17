#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdint>
#include <iostream>
#include <raft>
#include <chrono>
#include <cinttypes>

using cvm= typename cv::Mat;


template < class T > class source : public raft::kernel
{
public:
   source()
   {
      output.addPort< cvm >( "0" );
      if( ! stream1.isOpened() ) 
      { 
         std::cerr << "cannot open camera\n";
         exit( EXIT_FAILURE );
      }
   }

   virtual ~source()
   {
       stream1.release();
   }

   virtual raft::kstatus run()
   {
      fprintf( stdout, "source processing frame %" PRIu64 "\n", counter++ );
      auto &frame( output[ "0" ].template allocate< cvm >() );
      stream1.read( frame );
      output[ "0" ].send();
      return( raft::proceed );
   }

private:
   cv::VideoCapture stream1 = { 0 };
   std::uint64_t    counter = 0;
};

template < class T > class canny : public raft::kernel
{
public:
   canny()
   {
      input.addPort< T >( "0" );
      output.addPort< T >( "0" );
   }

   virtual ~canny() = default;

   virtual raft::kstatus run()
   {
      fprintf( stdout, "source processing frame %" PRIu64 "\n", counter++ );
      auto &img_in( input[ "0" ].template peek< T >() );
      auto &out( output[ "0" ].template allocate< T >() );
      cv::cvtColor( img_in, 
                    out, 
                    CV_BGR2GRAY );
      cv::blur(     out, 
                    out, 
                    cv::Size( 3, 3) );
      cv::Canny( img_in, 
                 out, 
                 thresh, 
                 thresh * 2, 
                 3 
           );

      input[ "0" ].unpeek();
      input[ "0" ].recycle( 1 );
      output[ "0" ].send();
      return( raft::proceed );
   }

private:
   const std::int8_t thresh = 100;
   std::uint64_t     counter = 0;
};

template < class T > class findcontours : public raft::kernel
{
public:
   findcontours()
   {
      input.addPort<  T >( "0" );
      output.addPort< T >( "0" );
   }

   virtual ~findcontours() = default;

   virtual raft::kstatus run()
   {
      auto &img_in( input[ "0" ].template peek< T >() );
      auto &out( output[ "0" ].  template allocate< T >() );
      cv::findContours( img_in,
                        contours,
                        hierarchy,
                        CV_RETR_TREE,
                        cv::CHAIN_APPROX_SIMPLE,
                        cv::Point() );
      out = cv::Mat::zeros( img_in.size(), 
                            CV_8UC3 );
      input[ "0" ].unpeek();
      input[ "0" ].recycle( 1 );
      for( auto i( 0 ); std::isless( i, contours.size() ); i++ )
      {
         cv::Scalar color( 
            cv::Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) ) );

         cv::drawContours( out, 
                           contours, 
                           i, 
                           color, 
                           2, 
                           8, 
                           hierarchy, 
                           0, 
                           cv::Point() 
                         );
      }
      output[ "0" ].send();
      return( raft::proceed );
   }

private:
   std::vector< std::vector< cv::Point > > contours;
   std::vector< cv::Vec4i>                 hierarchy;
   cv::RNG rng = { 12345 };
};

static std::uint64_t frames = 0;
static auto        start  = std::chrono::high_resolution_clock::now();
static auto        end    = std::chrono::high_resolution_clock::now();

template < class T > class display : public raft::kernel
{
public:
   display()          
   {
      input.addPort< cvm >( "0" );
   }
   
   virtual ~display() = default;
   
   virtual raft::kstatus run()
   {
      const auto &frame( input[ "0" ].template peek< cvm >() );
      cv::imshow( window_name, frame );
      input[ "0" ].unpeek();
      input[ "0" ].recycle( 1 );
      frames++;
      if( frames % 200 == 0 )
      {
         end = std::chrono::high_resolution_clock::now();
         const auto time( 
            std::chrono::duration_cast<
                std::chrono::duration< double > >( end - start ).count() 
         );
         const auto fps( frames / ( time ) );
         std::cout << fps << "\n";
      }
      return( raft::proceed );
   }
private:
   const std::string window_name = { "cam" };
};


int 
main()
{
   cv::namedWindow( "cam", cv::WINDOW_NORMAL );
   source< cvm >       src;
   canny< cvm >        cny;
   findcontours< cvm > fndcnt;
   display< cvm >      disp;
   
   raft::map m;
   /** what application pipeline looks like **/
   m += src >> cny >> fndcnt >> disp;
   /** start time for printing frame rate **/
   start =  std::chrono::high_resolution_clock::now();
   m.exe();
   return( EXIT_SUCCESS );
}

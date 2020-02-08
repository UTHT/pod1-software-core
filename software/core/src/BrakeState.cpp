#include "BrakeState.hpp"


#define CRITICAL_DISTANCE_THRESHOLD 500
#define CRITICAL_VELOCITY_THRESHOLD 10

BrakeState::BrakeState(): State(){
    this->position_channel_ptr = new Channel("position").subscribe();
    this->position = LCMTypePosition();

    this->velocity_channel_ptr = new Channel("velocity").subscribe();
    this->velocity = LCMTypeVelocity();

    this->brake_control_channel_ptr = new Channel("brake_control").subscribe();
}

States BrakeState::run(){
    /** For now we assume the only trigger to start braking is position.*/

    this->position_channel_ptr->handle(this->position);
    this->velocity_channel_ptr->handle(this->velocity);

    if(this->position.distance > CRITICAL_DISTANCE_THRESHOLD && this->velocity.velocity > CRITICAL_VELOCITY_THRESHOLD){
        return ESTOP;
    }
    if(this->velocity.velocity == 0){
        return OFF;
    }

    /** Whenever we are in this state, we will reissue the brake command assuming idempotency */
    this->brake_control_channel_ptr->publish( LCMTypeBrakeControl(true));

    return BRAKE;
}
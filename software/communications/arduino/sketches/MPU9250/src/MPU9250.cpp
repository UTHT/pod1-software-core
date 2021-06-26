#include "MPU9250.h"

const char *arr[10] = {"mg [X]", "mg [Y]", "mg [Z]", "deg/sec [X]", "deg/sec [Y]", "deg/sec [Z]", "mG [X]", "mG [Y]", "mG [Z]", "mg/Hz Peak [" FFT_AXIS "]"};
t_datasetup datasetup = {10, arr};

arduinoFFT FFT = arduinoFFT();
double vReal[SAMPLES];
double vImag[SAMPLES];
int count = 0;
double peak = 0.0;
double vibrationFreq;

MPU9250::MPU9250(arduino_t arduino) : Sensor(S_MPU9250, arduino, datasetup, 250) {
    this->mpu9250 = MPU9250_Lib(MPU9250_ADDRESS, I2Cport, I2Cclock);
}

errorlevel_t MPU9250::init() {
    Wire.begin();

    // Read the WHO_AM_I register, this is a good test of communication
    byte c = mpu9250.readByte(MPU9250_ADDRESS, WHO_AM_I_MPU9250);

    if (c != 0x71) // WHO_AM_I should always be 0x71
    {
        return ERR_FAIL;
    }
    else
    {
        // Self test and calibration
        // todo calibration check before the pod runs

        mpu9250.MPU9250SelfTest(mpu9250.selfTest);

        mpu9250.calibrateMPU9250(mpu9250.gyroBias, mpu9250.accelBias);
        mpu9250.initMPU9250();

        byte d = mpu9250.readByte(AK8963_ADDRESS, WHO_AM_I_AK8963);
        if (d != 0x48)
        {
            return ERR_FAIL;
        }

        mpu9250.initAK8963(mpu9250.factoryMagCalibration);

        // Get sensor resolutions, only need to do this once
        mpu9250.getAres();
        mpu9250.getGres();
        mpu9250.getMres();

        mpu9250.magCalMPU9250(mpu9250.magBias, mpu9250.magScale);
        return ERR_NONE;
    }
}

void getData(MPU9250_Lib *mpu9250)
{

    //Read Acceleration Raw
    mpu9250->readAccelData(mpu9250->accelCount);

    //Calculate acceleration in Gs
    mpu9250->ax = (float)mpu9250->accelCount[0] * mpu9250->aRes - mpu9250->accelBias[0];
    mpu9250->ay = (float)mpu9250->accelCount[1] * mpu9250->aRes - mpu9250->accelBias[1];
    mpu9250->az = (float)mpu9250->accelCount[2] * mpu9250->aRes - mpu9250->accelBias[2];

    //Read Gyro Raw
    mpu9250->readGyroData(mpu9250->gyroCount);

    //Calculate Gyro deg/sec
    mpu9250->gx = (float)mpu9250->gyroCount[0] * mpu9250->gRes;
    mpu9250->gy = (float)mpu9250->gyroCount[1] * mpu9250->gRes;
    mpu9250->gz = (float)mpu9250->gyroCount[2] * mpu9250->gRes;

    //Read Mag Raw
    mpu9250->readMagData(mpu9250->magCount);

    // Calculate Mag milligauss (mG)
    mpu9250->mx = (float)mpu9250->magCount[0] * mpu9250->mRes * mpu9250->factoryMagCalibration[0] - mpu9250->magBias[0];
    mpu9250->my = (float)mpu9250->magCount[1] * mpu9250->mRes * mpu9250->factoryMagCalibration[1] - mpu9250->magBias[1];
    mpu9250->mz = (float)mpu9250->magCount[2] * mpu9250->mRes * mpu9250->factoryMagCalibration[2] - mpu9250->magBias[2];
}

/*
 * Name: computeFFT
 * Function: Calculates vibration frequency from the accelerometer data vReal
 * Return: peak, the corresponding vib frequency
 */
double computeFFT(double vReal[]) {
    double vImag[SAMPLES] = {0.0};
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
    double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);
    return peak;
}

// TODO Calibrate imu readings
errorlevel_t MPU9250::read(t_datum *data, uint8_t numdata) {
    // NOTE: Convention - check that numdata given matches expected
    if (numdata != 9)
    { //TODO: globally declare the array size instead of using the int value
        return ERR_FAIL;
    }
    // Check if data ready
    if (mpu9250.readByte(MPU9250_ADDRESS, INT_STATUS) & 0x01) {
        getData(&mpu9250);
    }

    if (ENABLE_FFT) {
        // Collecting data for fourier transform
        // Can only be configured for one axis only, due to memory constraint
        // For other axes, set FFT_AXIS 'x', 'y', 'z'
        // switch (FFT_AXIS) {
        // case 'x':
        vReal[count] = (double)mpu9250.ax;
        //     break;
        // case 'y':
        //     vReal[count] = (double)mpu9250.ay;
        //     break;
        // case 'z':
        //     vReal[count] = (double)mpu9250.az;
        //     break;
        // }

        count++;
        if (count - 1 > SAMPLES) {
            peak = computeFFT(vReal);
            // Serial.print("vibration frequency: "); Serial.print(peak); Serial.println(" mg/Hz");
            count = 0;
        }
    }

    // Copy buffer
    data[0].data = (float)(1000 * mpu9250.ax);
    data[1].data = (float)(1000 * mpu9250.ay);
    data[2].data = (float)(1000 * mpu9250.az);
    data[3].data = (float)(mpu9250.gx);
    data[4].data = (float)(mpu9250.gy);
    data[5].data = (float)(mpu9250.gz);
    data[6].data = (float)(mpu9250.mx);
    data[7].data = (float)(mpu9250.my);
    data[8].data = (float)(mpu9250.mz);
    data[9].data = (float)peak;

    // TODO: other error conditions?
    return ERR_NONE;
}
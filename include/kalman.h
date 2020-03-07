//
// Created by dev on 1/11/20.
//

#ifndef FSG_SLAM_WS_KALMAN_H
#define FSG_SLAM_WS_KALMAN_H

float x_exp(float x_pv, float dx);

float deviation_exp(float deviation_pv, float variance);

float kalman_gain(float deviation_exp, float measure_dev);

float x_meas(float x_exp, float kalman_gain, float dist_meas);

float deviation_meas(float kalman_gain, float deviation_exp);




#endif //FSG_SLAM_WS_KALMAN_H

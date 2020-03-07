//
// Created by dev on 1/11/20.
//
#include "kalman.h"
#include <iostream>

using namespace std;

float x_exp(float x_pv, float dx){
    cout<<x_pv+dx<<endl;
    return x_pv+dx;
}

float deviation_exp(float deviation_pv, float variance){
    cout<<deviation_pv + variance<<endl;
    return deviation_pv + variance;
}

float kalman_gain(float deviation_exp, float measure_dev){
    cout<<deviation_exp/(deviation_exp+measure_dev)<<endl;
    return deviation_exp/(deviation_exp+measure_dev);
}

float x_meas(float x_exp, float kalman_gain, float dist_meas){
    cout<<x_exp + kalman_gain * (dist_meas - x_exp)<<endl;
    return x_exp + kalman_gain * (dist_meas - x_exp);
}

float deviation_meas(float kalman_gain, float deviation_exp){
    cout<<(1 - kalman_gain) * deviation_exp<<endl;
    return (1 - kalman_gain) * deviation_exp;
}

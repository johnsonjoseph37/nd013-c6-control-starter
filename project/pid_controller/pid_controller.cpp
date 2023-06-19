/**********************************************
 * Self-Driving Car Nano-degree - Udacity
 *  Created on: December 11, 2020
 *      Author: Mathilde Badoual
 **********************************************/

#include "pid_controller.h"
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kpi, double Kdi, double Kii, double output_lim_maxi, double output_lim_mini) {
   /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   **/
    Kp = Kpi;
    Kd = Kdi;
    Ki = Kii;
    output_lim_max = output_lim_maxi;
    output_lim_min = output_lim_mini;
    prev_cte = 0.0;
    diff_cte = 0.0;
    total_cte = 0.0;
    delta_time = 0.0;
}


void PID::UpdateError(double cte) {
   /**
   * TODO: Update PID errors based on cte.
   **/
    if (delta_time > 0) {
        diff_cte = (cte - prev_cte) / delta_time;
        total_cte += cte * delta_time;
        prev_cte = cte;
    }
}

double PID::TotalError() {
   /**
   * TODO: Calculate and return the total error
    * The code should return a value in the interval [output_lim_mini, output_lim_maxi]
   */
    double control = Kp * prev_cte + Kd * diff_cte + Ki * total_cte;
    return max(min(control, output_lim_max), output_lim_min);
}

double PID::UpdateDeltaTime(double new_delta_time) {
   /**
   * TODO: Update the delta time with new value
   */
    delta_time = new_delta_time;
}
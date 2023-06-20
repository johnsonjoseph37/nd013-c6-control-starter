# Control and Trajectory Tracking for Autonomous Vehicle

# Proportional-Integral-Derivative (PID)

In this project, you will apply the skills you have acquired in this course to design a PID controller to perform vehicle trajectory tracking. Given a trajectory as an array of locations, and a simulation environment, you will design and code a PID controller and test its efficiency on the CARLA simulator used in the industry.

### Installation

Run the following commands to install the starter code in the Udacity Workspace:

Clone the <a href="https://github.com/udacity/nd013-c6-control-starter/tree/master" target="_blank">repository</a>:

`git clone https://github.com/udacity/nd013-c6-control-starter.git`

## Run Carla Simulator

Open new window

* `su - student`
// Will say permission denied, ignore and continue
* `cd /opt/carla-simulator/`
* `SDL_VIDEODRIVER=offscreen ./CarlaUE4.sh -opengl`

## Compile and Run the Controller

Open new window

* `cd nd013-c6-control-starter/project`
* `./install-ubuntu.sh`
* `cd pid_controller/`
* `rm -rf rpclib`
* `git clone https://github.com/rpclib/rpclib.git`
* `cmake .`
* `make` (This last command compiles your c++ code, run it after every change in your code)

## Testing

To test your installation run the following commands.

* `cd nd013-c6-control-starter/project`
* `./run_main_pid.sh`
This will silently fail `ctrl + C` to stop
* `./run_main_pid.sh` (again)
Go to desktop mode to see CARLA

If error bind is already in use, or address already being used

* `ps -aux | grep carla`
* `kill id`


## Project Instructions

In the previous project you built a path planner for the autonomous vehicle. Now you will build the steer and throttle controller so that the car follows the trajectory.

You will design and run the a PID controller as described in the previous course.

In the directory [/pid_controller](https://github.com/udacity/nd013-c6-control-starter/tree/master/project/pid_controller)  you will find the files [pid_controller.cpp](https://github.com/udacity/nd013-c6-control-starter/blob/master/project/pid_controller/pid_controller.cpp)  and [pid_controller.h](https://github.com/udacity/nd013-c6-control-starter/blob/master/project/pid_controller/pid_controller.h). This is where you will code your pid controller.
The function pid is called in [main.cpp](https://github.com/udacity/nd013-c6-control-starter/blob/master/project/pid_controller/main.cpp).

### Step 1: Build the PID controller object
Complete the TODO in the [pid_controller.h](https://github.com/udacity/nd013-c6-control-starter/blob/master/project/pid_controller/pid_controller.h) and [pid_controller.cpp](https://github.com/udacity/nd013-c6-control-starter/blob/master/project/pid_controller/pid_controller.cpp).

Run the simulator and see in the desktop mode the car in the CARLA simulator. Take a screenshot and add it to your report. The car should not move in the simulation.

![image](https://github.com/johnsonjoseph37/nd013-c6-control-starter/assets/84423466/1430e303-0bf4-4e9b-8810-b1457147a485)

### Step 2: PID controller for throttle:
1) In [main.cpp](https://github.com/udacity/nd013-c6-control-starter/blob/master/project/pid_controller/main.cpp), complete the TODO (step 2) to compute the error for the throttle pid. The error is the speed difference between the actual speed and the desired speed.

Useful variables:
- The last point of **v_points** vector contains the velocity computed by the path planner.
- **velocity** contains the actual velocity.
- The output of the controller should be inside [-1, 1].

2) Comment your code to explain why did you computed the error this way.

3) Tune the parameters of the pid until you get satisfying results (a perfect trajectory is not expected).

### Step 3: PID controller for steer:
1) In [main.cpp](https://github.com/udacity/nd013-c6-control-starter/blob/master/project/pid_controller/main.cpp), complete the TODO (step 3) to compute the error for the steer pid. The error is the angle difference between the actual steer and the desired steer to reach the planned position.

Useful variables:
- The variable **y_points** and **x_point** gives the desired trajectory planned by the path_planner.
- **yaw** gives the actual rotational angle of the car.
- The output of the controller should be inside [-1.2, 1.2].
- If needed, the position of the car is stored in the variables **x_position**, **y_position** and **z_position**

2) Comment your code to explain why did you computed the error this way.

3) Tune the parameters of the pid until you get satisfying results (a perfect trajectory is not expected).

### Step 4: Evaluate the PID efficiency
The values of the error and the pid command are saved in thottle_data.txt and steer_data.txt.
Plot the saved values using the command (in nd013-c6-control-refresh/project):

```
python3 plot_pid.py
```

You might need to install a few additional python modules: 

```
pip3 install pandas
pip3 install matplotlib
```

Answer the following questions:
### - Add the plots to your report and explain them (describe what you see)

#### Attempt #1: Without sufficient P value, car does not steer well and collisions happen.
![image](https://github.com/johnsonjoseph37/nd013-c6-control-starter/assets/84423466/5e3f21e4-61ac-4bf4-9c94-cf4e1d8fa7c5)
![image](https://github.com/johnsonjoseph37/nd013-c6-control-starter/assets/84423466/cd7e9b56-1977-4101-9ca3-a3145db5f096)
![image](https://github.com/johnsonjoseph37/nd013-c6-control-starter/assets/84423466/db264b33-6efa-44c3-ae5f-4ebad8798649)


#### Attempt #2: Increasing P value gets a decent error tracking, but there is lot of oscillation.
![image](https://github.com/johnsonjoseph37/nd013-c6-control-starter/assets/84423466/3b9b06b6-fffb-4700-a2f7-00beb0902366)
![image](https://github.com/johnsonjoseph37/nd013-c6-control-starter/assets/84423466/76bed0a8-f58a-4314-9a23-7ac8e68cc1fa)
![image](https://github.com/johnsonjoseph37/nd013-c6-control-starter/assets/84423466/720ba8a7-9a4d-4bd7-8308-92c68a19cb06)


#### Attempt #3: Tuning/increasing D value reduces the oscillation, a lot!
![image](https://github.com/johnsonjoseph37/nd013-c6-control-starter/assets/84423466/44baf6ec-acab-476a-9477-26d5d98135c1)
![image](https://github.com/johnsonjoseph37/nd013-c6-control-starter/assets/84423466/9cf5d8ac-7481-4a62-b10e-150d766db2a1)
![image](https://github.com/johnsonjoseph37/nd013-c6-control-starter/assets/84423466/79212034-ee9c-419f-83f1-e9659f4e9236)

#### Attempt #4: Tuning/decreasing I value reduces bias, helping car to stay inside the lane.
![image](https://github.com/johnsonjoseph37/nd013-c6-control-starter/assets/84423466/8e4d7034-8490-4e5b-8706-c1ba1b81f47d)
![image](https://github.com/johnsonjoseph37/nd013-c6-control-starter/assets/84423466/76cfbe15-a760-40ae-ba6b-56169cba32b0)
![image](https://github.com/johnsonjoseph37/nd013-c6-control-starter/assets/84423466/9f0cd67b-fd79-418f-a8cc-87fce79a8b4b)


### - What is the effect of the PID according to the plots, how each part of the PID affects the control command?

1) Without sufficient P value, car does not steer well and collisions happen.
2) Tuning D value helps in reducing the oscillation.
3) Tuning I value helps the car to stay inside the lane, due to compensation of bias error.


### - How would you design a way to automatically tune the PID parameters?

Twiddle algorithm presented in the course is one option. This is an iterative process that searches for a minima. Like all optimization algorithms, care should be taken to avoid local minima, which can be achieved by repeating search, using random starting parameters.

### - PID controller is a model free controller, i.e. it does not use a model of the car. Could you explain the pros and cons of this type of controller?

Being model-free keeps the controller simple and calculations easy to implement and fast at run time. However, as the vehicle becomes larger (like a trailer) and the roads become curvier, the cross tracking error based on simple bicycle model might lead to incorrect steer and throttle.

### - (Optional) What would you do to improve the PID controller?

Addition of information about size and shape of vehicle into calculations of steer and throttle is needed for real life scenarios.

### Tips:

- When you wil be testing your c++ code, restart the Carla simulator to remove the former car from the simulation.
- If the simulation freezes on the desktop mode but is still running on the terminal, close the desktop and restart it.
- When you will be tuning the PID parameters, try between those values:


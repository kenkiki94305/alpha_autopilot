#include <alpha_drivers/decoder/GPIO_RPI.h>
#include <alpha_drivers/decoder/RCInput_RPI.h>
#include <alpha_drivers/decoder/Scheduler.h>
#include <ros/ros.h>

int main(int argc, char* argv[]){
  ros::init(argc,argv,"sbus_decoder");
  Scheduler scheduler;
  GPIO_RPI gpio;
  RCInput_RPI rcin;
  rcin.set_scheduler(&scheduler);
  rcin.set_gpio(&gpio);
  scheduler.setRCInput(&rcin);

  scheduler.init();
  gpio.init();
  rcin.init();
  scheduler.system_initialized();

}

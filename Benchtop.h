#ifndef Benchtop_h
#define Benchtop_h

#include "Arduino.h"

class Benchtop {
  
   public:
        /*
         * Constructor for Benchtop object
         *          
         */
        Benchtop();        
    
       
        /*
         * Sets the syringe rinse speed
         * 
         * @param syringe_rinse_speed to set
         */
        void set_syringe_rinse_speed(float syringe_rinse_speed);

        /*
         * Gets the syringe rinse speed         
         */
        float get_syringe_rinse_speed();

         /*
         * Sets the rinse volume
         * 
         * @param rinse_volume to set
         */
        void set_rinse_volume(float rinse_volume);

        /*
         * Gets the rinse volume
         */
        float get_rinse_volume();

        /*
         * Sets the rinse time
         * 
         * @param rinse_time to set
         */
        void set_rinse_time(float rinse_time);

        /*
         * Gets the rinse time
         */
        float get_rinse_time();

        /*
         * Sets the acid volume
         * 
         * @param acid_volume to set
         */
        void set_acid_volume(float acid_volume);

        /*
         * Gets the acid volume
         */
        float get_acid_volume();

        /*
         * Sets the acid wait time
         * 
         * @param acid_wait_time to set
         */
        void set_acid_wait_time(float acid_wait_time);

        /*
         * Gets the acid wait time
         */
        float get_acid_wait_time();
        
        /*
         * Sets the sample volume
         * 
         * @param sample_volume to set
         */
        void set_sample_volume(float sample_volume);

        /*
         * Gets the sample volume
         */
        float get_sample_volume();

        /*
         * Sets the syringe sample speed
         * 
         * @param syringe_sample_speed to set
         */
        void set_syringe_sample_speed(float syringe_sample_speed);

        /*
         * Gets the syringe sample speed
         */
        float get_syringe_sample_speed();

        /*
         * Sets the sample wait time
         * 
         * @param sample_wait_time to set
         */
        void set_sample_wait_time(float sample_wait_time);

        /*
         * Gets the sample wait time
         */
        float get_sample_wait_time();

        /*
         * Sets the total sample integration time
         * 
         * @param total_sample_integration_time to set
         */
        void set_total_sample_integration_time(float total_sample_integration_time);

        /*
         * Gets the total sample integration time
         */
        float get_total_sample_integration_time();   
    
    private:
        float syringe_rinse_speed;
        float rinse_volume;
        float rinse_time;
        float acid_volume;
        float acid_wait_time;
        float sample_volume;
        float syringe_sample_speed;
        float sample_wait_time;
        float total_sample_integration_time;                 
};

#endif

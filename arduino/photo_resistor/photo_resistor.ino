// DC Voltage Module without LCD Display Shield By Solarduino 

// Note Summary
// Note :  Safety is very important when dealing with electricity. We take no responsibilities while you do it at your own risk.
// Note :  This DC Votlage Sensor Code is for Voltage Divider Method or related DC voltage module use.
// Note :  The value shown in Serial Monitor is refreshed every second.
// Note :  The voltage measured is direct measurement based on 1 sample only and is not an average value.
// Note :  No calibration is needed. 
// Note :  The unit provides reasonable accuracy and may not be comparable with other expensive branded and commercial product.
// Note :  All credit shall be given to Solarduino.

/*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/////////////*/


/* 1 - DC Voltage Measurement */

    int analogInputPin = A2;                    // This is the analog input pin number in arduino for voltage sensing.  
    float vArduino = 0.0;                       /* This is the value voltage sensed by arduino in 0-5 volt */ 
    float vActual = 0.0;                        /* This is the actual voltage that being measured or monitored*/
    float R1 = 30000.0;                         // This is the resistance (in ohm) of R1. You may change this value based on the resistor you use. 
    float R2 = 7500.0;                          // This is the resistance (in ohm) of R2. You may change this value based on the resistor you use. 
    int rawValueRead= 0;                        /* This is the raw value / analog value detected by Arduino ranges 0 - 1023*/


void setup()
{
     
    /* 1 - DC Voltage Measurement */
    
    pinMode(analogInputPin, INPUT);             /* Declare analog pin as an input*/
    Serial.begin(9600);                         /* Initialise the Serial Monitor function. The Serial Monitor available at 9600 baud rate*/
    Serial.println("DC VOLTMETER");             /* Describe the function code displayed in Serial Monitor*/
    
    
}


void loop()

{
    /* 1 - DC Voltage Measurement */
    
    rawValueRead = analogRead(analogInputPin);        /* Read and collect sensor from analog input pin in raw data (0-1023) values */
    vArduino = (rawValueRead * 5.0) / 1024.0;         /* Convert the raw data value into 0 - 5V measurable voltage at analog input pin*/
    vActual = vArduino / (R2/(R1+R2));                /* Calculate the expected monitoring voltage in full voltage*/
    
    Serial.print("Vdc = "); 
    Serial.println(vActual,2);                        /* Print out the result in Serial Monitor, in 2 decimal places*/
    delay(1000);                                      /* Delay or pause for 1.000 seconds*/

    
}

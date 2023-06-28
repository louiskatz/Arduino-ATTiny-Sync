/*Notes

This program was originally written for the ATTiny85 Processsors in Beat Frequency, a piece by Louis Katz displayed at KSpace Contemporary in 2023.  
The piece has 30 X four microprocessors and four individual programs.  So thirty ATTinys had to remain synced. I considered a common clock. This 
raises all sorts of technical issues as doe transmitting the same high speed digital signal at a distance to thirty boards. A 2 hz clock signal is a different issue and easy. 
You should use a pulldown resistor on the sync pins. It seems that 20K Ohms is enough 

To use this connect the MASTER_SYNC_PINE to the SYNC_PIN's and tie them to ground with an  ~20K Ohm resistor. 













*/
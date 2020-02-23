# ECE 16 Lab Report 4
Prepared By: Owen Bartolf | Date: 2/13/2020

## Tutorial
> ### MAX30105 Pulse Sensor
>
> ---
>
> Here is a demo of the Heartbeat Plotter tutorial in action.
> ![Image](fig/Lab4/tutorial_heartbeatPlotter.gif)
>
> **Q. Note that you can connect both the heart rate sensor and your OLED at the same time, both of which use the I2C SDA and SCL lines. Why does this work?**
>
> We can due this because of how I2C as a protocol is designed. Every I2C device is assigned an address. Whenever a message is to be transmitted to a device on an I2C wire, the protocol first sends the address towards which the transmission is directed. In protocol design, this is called sending a "header." The message is then only processed by the device whose address matches the header information. This allows multiple devices to be "chained" together on a single I2C wire.
>
> **Q. Notice the while(1) statement. What happens if the device is not connected? What happens if the error is printed and then you connect the device? Will the code proceed? Try it and describe the behavior.**
>
> If the device is not connected, an error message is printed and the program hangs. While the ```while(1)``` statement does not have a body defined, the statement still executes. Because the loop's conditional has no scenario where it will evaluate to false, the program will hang indefinitely at the statement if the device is not detected. Even if the device is reconnected, the program will still hang indefinitely for the same reason.
>
> This makes sense; we do not want to execute a program if the hardware that is critical for its execution is unavailable or otherwise does not exist! We also don't want to write super-complicated code to detect a loss of connection and attempt to re-establish it on a device where a loss of connection probably means there is unavoidable damage to the actual hardware.
> 
> **Q. what would the settings look like if you were to: set the led brightness to 25mA, use only the Red + IR LED, Sample at 200Hz, and use an ADC range of 8192?**
>
> The following settings should do the trick...
>
> ```c
> byte ledBrightness = 127; //Options: 0=Off  to 255=50mA
> byte sampleAverage = 8; //Options: 1, 2, 4,  8, 16, 32
> byte ledMode = 2; //Options: 1 = Red only,  2 = Red + IR, 3 = Red + IR + Green
> int sampleRate = 200; //Options: 50, 100,  200, 400, 800, 1000, 1600, 3200
> int pulseWidth = 411; //Options: 69, 118,  215, 411
> int adcRange = 8192; //Options: 2048, 4096,  8192, 16384
> ```
> **Q. What are the units of the pulse width? Would the bigger the pulseWidth result in a more intense or less intense measurement? Why?**
>
> According to the datasheet, the units for pulse width are microseconds (µs). 
> 
> **Q. How many bits are needed for an ADC range of 16384?**
>
> 2 to the power of 14 is 16384. Therefore, for an ADC range of 16384, we need to use a primitive with at least 14 bits wide. If we use less, we will encounter overflow issues.
>
> **Q. What is the peak wavelength of the R, IR, and G LEDs?**
>
> Below are the peak wavelengths for each LED as taken from the particle sensor datasheet. 
>
> | LED      | Min Peak λ | Typical Peak λ | Max Peak λ |
> |----------|------------|----------------|------------|
> | Red      | 650        | 660            | 670        |
> | Green    | 530        | 537            | 545        |
> | Infrared | 870        | 880            | 900        |
>
> **Q. If you want to read the Green value, what Mode do you need the setting to be in and what function will you need to use to get the green signal?**
>
> The mode must be 3; in no other mode is the green LED activated. Then, ```particleSensor.getGreen()``` should be called.
>
> ### Tutorial 2: Matplotlib
> 
> **Q. What was plotted? What does this tell you about how plt.plot interprets the input?**
>
> The following image was plotted...
>
> ![Image](fig/Lab4/tutorialPlot.png)
>
> As we can see, the plt.plot() function plots a line for each column in a numpy matrix. In other words, plt.plot() interprets the input matrix as a list of sets, where each column is a plottable set.
>
> ### Tutorial 3: Saving and Reading via IO
>
> The file that was to be generated in the tutorial can be found ![here.](data/Lab4/foo.csv)
>
> **Q. Try your best to replicate the above plot by shaking your accelerometer. The above was sampled at 50Hz for 10 seconds. Make a gif of you running your program, shaking your accelerometer, and a plot showing up similar to the one above.**
>
> 
>
> **Q. What is approximately the frequency of oscillation of the x axis signal in the plot above?**
>
> ![Image](fig/Lab4/frequencyCalculation.png)
>
> The chart represents ten seconds of samples. If we tesselate the sequence of shakes across the entire sample space, we discover that we can tesselate up to five sequences over the entire interval. In other words, this means that over ten seconds, we could fit five sequences of shakes, so each sequence of shakes is 2 seconds long.
>
> From there, it's a simple frequency calculation.
>
> Frequency = Cycles / Seconds
>
> Frequency = 4 cycles / 2 seconds
>
> **Frequency = 2 Hz**
>
> ### Tutorial 4: Removing Mean Offset
>
> I did this task successfully! Orange is zeroed; I tapped the hardware about one time per second.
>
> ![Image](fig/Lab4/meanOffsetRemoved.png)
>
> ### Tutorial 5: Smoothing with Moving Average
> 
> **Q. Try different n_avg and document, with plots, the result for a few different n_avg and describe which n_avg worked well in emphasizing the taps?**
>
> I tried a few values, here are the highlights, where green is the plotted moving average...
>
> 5 Samples.
>
> ![Image](fig/Lab4/detrend5.png)
>
> I think 10 samples worked the best for the moving average. It hits a pretty good balance between having a running history, but not having that history be too long as to make it meaningless.
>
> ![Image](fig/Lab4/detrend10.png)
>
> 10 samples again, but with a high amount of motion. Still works pretty well...
>
> ![Image](fig/Lab4/detrend10HighMotion.png)
>
> A Bigger value doesn't always mean a better reduction; in fact, large values like 50 tended to provide ill results. This is because when the moving average goes back so far, slow changes have a much greater weight on the overall mean of the current value. For example, check out the plot for Detrend 20:
>
> ![Image](fig/Lab4/detrend20.png)
>
> ### Tutorial 6: Looking at the Signal in Differnt Ways
>
> **Q. Try using np.diff(s) to calculate the gradient of the signal s and plot the signal.**
>
> Here is the plot that shows the difference over time. It's the red line. As you can see, it's way more effective than the other methods for detecting taps vs. regular variation.
>
> ![Image](fig/Lab4/diff.png)
> 
> 
## Challenge 1

## Challenge 2
# panic-nap
This is a little C script I threw together for my frame.work laptop running Void Linux. It checks the current battery percentage every second, and if the percentage dips below 5% the script hibernates my laptop to disk, so when I charge it again I didn't lose any progress. This was made **specifically** for my laptop and its set up, meaning that this script might not work for you, user beware. 

## Building
Note: This is a Linux only script, this depends upon the sysfs of the Linux kernel to function.
```sh
git clone https://github.com/Nythepegasus/panic-nap
cd panic-nap
make
```
That easy :)

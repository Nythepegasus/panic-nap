#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void hibernate(){
	FILE *disk = fopen("/sys/power/disk", "w");
	FILE *state = fopen("/sys/power/state", "w");
	if (disk == NULL) {
		printf("Couldn't open /sys/power/disk!\n");
		exit(1);
	}
	if (state == NULL) { 
		printf("Couldn't open /sys/power/state!\n");
		exit(1);
	}

	fprintf(disk, "platform");
	fprintf(state, "disk");

	fclose(disk);
	fclose(state);
}

float current_battery_level(){
	int f, c;
	FILE *full = fopen("/sys/class/power_supply/BAT1/charge_full", "r");
	FILE *curr = fopen("/sys/class/power_supply/BAT1/charge_now", "r");
	if (full == NULL){
		printf("Couldn't open charge_full!\n");
		exit(1);
	}
	if (curr == NULL){
		printf("Couldn't open charge_now!\n");
		exit(1);
	}
	fscanf(full, "%d", &f);
	fscanf(curr, "%d", &c);

	fclose(full);
	fclose(curr);

	return (float)c / (float)f;
}

int main(){
	while(1){
		printf("%f\n", current_battery_level());
		if (0.05 > current_battery_level()) hibernate();
		sleep(1);
	}
	return 0;
}

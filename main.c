#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <assert.h>

#include "controller.h"

int main(int argc, char *argv[]){
	int ret=0;
	//ZNS SSD Init
	printf("ZNS SSD : Init\n");
	printf("\n");
	
//	struct timeval start, end, gap;
//	float time = 0.0f;
//	std::string dev("/dev/nvme0n1");
	zns_get_info("/dev/nvme0n1");
	zns_get_zone_desc(REPORT_ALL, REPORT_ALL_STATE, 0, 0, true);
	printf("Initial state of Zone\n");
	printf("↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
	print_zone_desc(11);

	for(unsigned int i=0; i < 28729; i++){
		zns_set_zone(i, MAN_RESET);
	}


//	print_zone_desc(10);

	/*
	void* test_data = malloc(_192KB);
	memset(test_data, 'W', _192KB);
	zns_set_zone(0, MAN_OPEN);
	
	gettimeofday(&start, NULL);
	zns_write(test_data, _192KB, 0);
	gettimeofday(&end, NULL);
	
	zns_set_zone(0, MAN_CLOSE);
	time = (end.tv_sec - start.tv_sec) + ((end.tv_usec - start.tv_usec) * 0.000001);


	printf("after writing zone\n");

	printf("↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓\n");
	*/
	//print_zone_desc(2);
	/*
	if(gap.tv_usec < 0){
		gap.tv_sec = gap.tv_sec-1;
		gap.tv_usec = gap.tv_usec + 1000000;
	}

	printf("Elpased time %f sec\n", time);
	*/	
	return ret;

}

#include <stdio.h>
#include "controller.h"

int main(int argc, char *argv[]){
	int ret;
	//ZNS SSD Init
	printf("ZNS SSD : Init\n");
//	std::cout << "ZNS SSD : Init" << std::endl;
//	std::string dev("/dev/nvme0n1");
	
	ret = zns_get_info("/dev/nvme0n1");
	zns_get_zone_desc(REPORT_ALL, REPORT_ALL_STATE, 0, 0, true);
	
	
	for(unsigned int i=0; i < 100; i++){
		zns_set_zone(i, MAN_RESET);
	}


	
	void* test_data = malloc(_192KB);
	memset(test_data, 'W', _192KB);
	
	zns_set_zone(0, MAN_OPEN);
	zns_write(test_data, _192KB, 0);

	print_zone_desc(0);

	return 0;
}

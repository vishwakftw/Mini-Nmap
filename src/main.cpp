#include <iostream>
#include <queue>
#include "discover.h"
#include "logger.h"

int main() {
	Ping::timeout = 5e5;
	Logger::logLevel = Logger::DEBUG;
	/* test ping  */

	Discover obj;
	std::tuple<std::string, int> a = obj.split_CIDR("10.0.0.0/24");
	std::queue <Discover::request*> test= obj.handle_CIDR(std::get<0>(a), std::get<1>(a));
	obj.discover_host(test);



	// Ping obj;
	// int sockfd = obj.open_icmp_socket();
	// obj.set_src_addr(sockfd, obj.get_my_IP_address("enp7s0"));
	// while(true) {
	// 	obj.ping_request(sockfd, "192.168.35.7", 1);
	// 	obj.ping_reply(sockfd);
	// }
    return 0;
}
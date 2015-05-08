~DDoS Attack Final Project and Implementations~

For my final project, I have implemented some different types of DDoS attacks, specifically UDP flood, TCP SYN flood, and TCP PSH+ACK flood. The UDP Flood, TCP SYN Flood, TCP PSH+ACK Flood folders have scripts to simulate those types of attacks and the Test Site folder has a victim site to test the attacks on.

~Types of Attacks~

UDP DDoS Flood

During UDP flood attack, victim is receiving large number of UDP packets through specified or random ports and will get flooded trying to process all incoming data. An ICMP packet is sent if the victim system is not running any applications on a targeted port.

TCP SYN Flood

In a DDoS TCP SYN attack, the attacker instructs the bots to send bogus TCP SYN requests to a victim server in order to tie up the server’s processor resources, and hence prevent the server from responding to legitimate requests. The TCP SYN attack exploits the three-way handshake between the sending system and the receiving system by sending large volumes of TCP SYN packets to the victim system with spoofed source IP addresses, so the victim system responds to a non-requesting system with the ACK+SYN. When a large volume of SYN requests are being processed by a server and none of the ACK+SYN responses are returned, the server eventually runs out of processor and memory resources, and is unable to respond to legitimate users

TCP PSH+ACK Flood

In a PUSH + ACK attack, the attacking agents send TCP packets with the PUSH and ACK bits set to one. These triggers in the TCP packet header instruct the victim system to unload all data in the TCP buffer (regardless of whether or not the buffer is full) and send an acknowledgement when complete. If this process is repeated with multiple agents, the receiving system cannot process the large volume of incoming packets and the victim system will crash.

~Requirements~

In order to run the programs and scripts, nmap, sshpass, and hping3 must be installed on the attack machine. The bots have to be in the network and the attack machine must be their system administrator. Due to difficulty of implementation, it is assumed that the attack machine knows the username and password credentials of the bots and that they are the same across the network. The bots also need ssh enabled on them. The victim is a computer hosting a website (nginx web-server) and will be used to test whether the attacks are successful. 

~Files~ 

findBots.py

Script uses nmap tool to find bots in the network and saves results in mybots.xml file. The script then parses the file to look for systems which are up with unfiltered port and saves the IPs of those systems in list.txt.

botController.c

This code takes the username and password of the bots as well as the attack script (udp.py, tcp_syn.py, tcp_psh_ack.py) and implement the attack accordingly. Varying specific lines in the attack scripts can be altered to change the attack duration or victim’s IP address.

udp.py, tcp_syn.py, tcp_psh_ack.py

Scripts which execute respective DDoS attacks.

~Run Instructions~

For each type of attack, the following instructions will run the program/script. 

	 $sudo python findBots.py
	 $gcc -pthread botMaker.c
	 $./a.out

Output

Login screens for connected and unsuccessfully connected hosts will be shown and success will be printed after the attack finishes.
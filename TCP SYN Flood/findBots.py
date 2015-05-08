from xml.dom import minidom 
import os

ip_list = []

#edit this line for network being used to create bots
os.system("nmap -sA 10.1.12.0/24 -oX nmapOP.xml") 
bot_list = minidom.parse('nmapOP.xml')
bots = bot_list.getElementsByTagName('host')


for node in bots:
    filterCheck = node.getElementsByTagName('extraports')
    for eachCheck in filterCheck:
        check =  eachCheck.getAttribute('state')
        if(check == "unfiltered"):
		    Addr = node.getElementsByTagName('address')
		    for ip in Addr:
		    	if(ip.getAttribute('addrtype')=='ipv4'):
		    	    print str(ip.getAttribute('addr'))
		            ip_list.append(str(ip.getAttribute('addr')))
g = open("list.txt","w")

for i in ip_list:
    g.write(i)
    g.write('\n')
g.close()
One node Mcu is connected with Arduino power supply of 
3.3 V and Ground and made as Access Point

another Node MCU is programmed as client 


client node mcu connects to access point node mcu 
client node mcu sends http get request with following address
/ip/Tempearature
/ip/Humidity
/ip/Pressure

access point node mcu is attached with Webserver (80)

usually ip 192.168.1.4
receives the get request from client
and sends back value associated with page /temperture
/humidity / pressure


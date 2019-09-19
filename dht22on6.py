#DHT22
#dht22 loop
#
#dht22 on pin 6
#converts Celcius to Farenheit
#!/usr/bin/python
import sys
import Adafruit_DHT

while True:

    humidity, temperature = Adafruit_DHT.read_retry(22, 6)
    temperature = temperature * 9/5.0 + 32
    print 'DHT22 pin 6 Sensor Temperature: {0:0.1f} F Humidity: {1:0.1f} %'.format(temperature, humidity)




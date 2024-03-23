import serial
import threading
import time

# Global variable for serial connection
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=5)

# Function to continuously read data from Arduino
def read_data():
    while True:
        data = arduino.readline().decode('utf-8').strip()
        if data:
            print("Received data from Arduino:", data)

# Function to send commands to Arduino
def send_command():
    while True:
        num = input("Enter command: ")
        arduino.write(num.encode('utf-8'))
        print("Command sent to Arduino")

try:
    # Create two threads
    read_thread = threading.Thread(target=read_data)
    send_thread = threading.Thread(target=send_command)

    # Start both threads
    read_thread.start()
    send_thread.start()

    # Keep the main thread running
    read_thread.join()
    send_thread.join()

finally:
    arduino.close()  # Close the serial port when done

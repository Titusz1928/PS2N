import serial
import threading
import time

from flask import Flask, render_template, url_for, redirect

app = Flask(__name__)



def send_command(command):
    arduino.write(command.encode('utf-8'))


@app.route("/turn-on", methods=["POST"])
def turn_on():
    send_command("A")  # Send command to turn LED on
    #time.sleep(3)
    return redirect(url_for('posts'))


@app.route("/turn-off", methods=["POST"])
def turn_off():
    send_command("S")  # Send command to turn LED off
    #time.sleep(3)
    return redirect(url_for('posts'))

@app.route("/temp_refresh", methods=["GET", "POST"])
def temp_refresh():
    print("refresh")
    send_command("T")
    return redirect(url_for('posts'))

@app.route("/")
def home():
    return render_template('home/index.html')

statusLed = "None"
data = 20

arduino = serial.Serial(port='COM3', baudrate=9600, timeout=10)
@app.route("/posts")
def posts():
    global data
    global statusLed

    #time.sleep(3)
    #arduino = serial.Serial(port='COM3', baudrate=9600, timeout=10)
    data = arduino.readline().decode('utf-8').strip()
    parts = data.split(' ', 1)
    data = parts[0]
    print(data)
    aux=statusLed
    statusLed = parts[1] if len(parts) > 1 else aux
    print(statusLed)
    return render_template('posts/index.html', sensor_data=data, status_led=statusLed)
    #return render_template('posts/index.html')
    arduino.close()

if __name__ == "__main__":
    # Run the Flask app with host set to '0.0.0.0' and port set to 4000
    app.run(host='0.0.0.0', port=4000)
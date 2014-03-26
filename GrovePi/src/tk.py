tk = Tk()

# Add a canvas area ready for drawing on
sensorButton = Button(tk,text="Update Air Quality Value",command=Analog)
sensorButton.pack()

# Add an exit button
exitButton = Button(tk, text="Exit", command=terminate)
exitButton.pack()

label1 = Label(tk)
label1.pack()
label1.configure(text=("Sensor Value = %d")% grovepi.analogRead(0))

label2 = Label(tk)
label2.pack()

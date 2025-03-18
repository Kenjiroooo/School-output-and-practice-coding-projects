# Finals Exam BSCpE 1
print("Kenji Sakamoto")
print("Unit Conversion")
print("Option 1. Weight")
print("Option 2. Temperature")
print("Option 3. Length")

operator = input()
# WEIGHT
if operator == "1":
    weight = float(input('weight: '))
    unit = input('(L)bs or (K)g or (T)Ton: ')
    if unit.upper() == "L":
        converted = weight * 0.45
        print(f"The Weight is {converted} kilos from pounds")
    elif unit.upper() == "K":
        converted = weight / 0.45
        print(f"The Weight is {converted} pounds from kilo")
    elif unit.upper() == "T":
        converted = weight * 1000
        print(f"The Weight is {converted} kg from tons")
    else:
        print("Input Error, Please Try Again")
# TEMPERATURE
elif operator == "2":
    temp = float(input('Temperature: '))
    unit = input('(C)Celsius or (F)Fahrenheit or (K)Kelvin: ')
    if unit.upper() == "C":
        converted = (temp * 9/5) + 32
        print(f"The temperature is {converted} Fahrenheit from Celsius")
    elif unit.upper() == "F":
        converted = (temp - 32) * 5/9
        print(f"The temperature is {converted} Celsius from Fahrenheit")
    elif unit.upper() == "K":
        converted = temp + 273.15
        print(f"The temperature is {converted} Kelvin from Celsius")
    else:
        print("Input Error, Please Try Again.")
# LENGTH
elif operator == "3":
    speed = float(input('Length: '))
    unit = input('(K)Kilometer or (M)Mile or (F)Foot')
    if unit.upper() == "K":
        converted = speed * 0.62
        print(f"The length is {converted} Mile from Kilometer")
    elif unit.upper() == "M":
        converted = speed * 1.61
        print(f"The length is {converted} kilometers from miles")
    elif unit.upper() == "F":
        converted = speed * 0.0003
        print(f"The length is {converted} Kilometer from foot")
    else:
        print("Input Error, Please Try Again.")
else:
    print("Input Invalid, Choose only from the given Options")

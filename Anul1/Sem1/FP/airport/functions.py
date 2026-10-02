def add(flights, code, duration, dep_c, dest_c):
    '''
    :param flights: the lsit of flights
    :param code: the code of the flight
    :param duration: the duration of the flight
    :param dep_c: the departure city of the flight
    :param dest_c: the destination city of the flight
    :return: a new list of flights with an added flights
    '''
    if len(code) < 3 or len(dep_c) < 3 or len(dest_c) < 3:
        raise ValueError("The length has to be greater than 3")
    if int(duration) < 20:
        raise ValueError("The duration has to be greater than 20")
    duration = int(duration)
    new_flight = {"code":code, "duration":duration, "dep_c":dep_c, "dest_c":dest_c}
    flights.append(new_flight)
    return flights

def delete(flights, code):
    '''
    :param flights: a list of flights
    :param code: a code of the flight
    :return: delete a flight with a specific code
    '''
    new_flights = []
    for flight in flights:
        if flight["code"] != code:
            new_flights.append(flight)
    return new_flights

def show(flights, dep_c):
    '''
    :param flights: the lsit of flights
    :param dep_c: the departure city of the flight
    :return: display the flights with a specific departure city and sorted ascending by destination city
    '''
    new_flights = []
    for flight in flights:
        if flight["dep_c"] == dep_c:
            new_flights.append(flight)
    sorted_flights = sorted(new_flights, key = lambda x: x["dest_c"])
    return sorted_flights

def inc(flights, dep_c, minutes):
    '''
    :param flights: a list of flights
    :param dep_c: the departure city of the flight
    :param minutes: the minutes we want to increase
    :return: the list updated with the duration increased by the number of minutes
    '''
    new_flights = []
    minutes = int(minutes)
    if minutes < 10 or minutes > 60:
        raise ValueError("The minutes has to be between 10 and 60")
    for flight in flights:
        if flight["dep_c"] == dep_c:
            flight["duration"] += minutes
        new_flights.append(flight)
    return new_flights

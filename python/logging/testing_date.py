import datetime

current_time: datetime.datetime = datetime.datetime.now()

print(current_time.strftime("%Y%m%d_%H%M%S"))

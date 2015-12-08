from django.contrib import admin
from .models import AirplaneTicket, BusTicket, TrainTicket

# Register your models here.
admin.register(AirplaneTicket, BusTicket, TrainTicket)

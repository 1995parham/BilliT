from django.db import models


class BusTicket(models.Model):
    src_town = models.CharField(max_length=1024, verbose_name="Source Town")
    dst_town = models.CharField(max_length=1024, verbose_name="Destination Town")
    buyer = models.ForeignKey('user.User')
    fi = models.DecimalField()
    dispatch_time = models.DateTimeField()


class AirplaneTicket(models.Model):
    src_town = models.CharField(max_length=1024, verbose_name="Source Town")
    dst_town = models.CharField(max_length=1024, verbose_name="Destination Town")
    buyer = models.ForeignKey('user.User')
    flight_no = models.DecimalField()
    fi = models.DecimalField()
    dispatch_time = models.DateTimeField()


class TrainTicket(models.Model):
    src_town = models.CharField(max_length=1024, verbose_name="Source Town")
    dst_town = models.CharField(max_length=1024, verbose_name="Destination Town")
    buyer = models.ForeignKey('user.User')
    fi = models.DecimalField()
    dispatch_time = models.DateTimeField()

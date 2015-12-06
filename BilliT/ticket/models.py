from django.db import models


class Ticket(models.Model):
    src_town = models.CharField(max_length=1024)
    dst_town = models.CharField(max_length=1024)

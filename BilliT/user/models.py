from django.db import models
from django.contrib.auth.models import AbstractUser
from django.core.urlresolvers import reverse


class User(AbstractUser):
    s_id = models.CharField(verbose_name="Social Number", max_length=10)
    home_town = models.CharField(verbose_name="Home Town", max_length=1024)
    birthday = models.DateField(verbose_name="Birthday")
    career = models.CharField(max_length=1024, verbose_name="Career")

    def get_full_name(self):
        return self.last_name

    def get_short_name(self):
        return self.first_name

    def get_absolute_url(self):
        return reverse('user_detail', args=[str(self.pk)])

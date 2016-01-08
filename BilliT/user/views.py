from django.contrib.auth import authenticate, login
from django.shortcuts import redirect
from django.shortcuts import render
from django.views.generic.edit import FormView

from .forms import LoginForm


class UserLogin(FormView):
    template_name = 'user/login.html'
    form_class = LoginForm

    def get_initial(self):
        kwargs = super(UserLogin, self).get_initial()
        next_url = self.request.GET.get('next', None)
        if next_url:
            kwargs.update({'next': next_url})
        return kwargs

    def form_valid(self, form):
        next_url = form.cleaned_data.get('next', None)
        username = form.cleaned_data['username']
        password = form.cleaned_data['password']

        print(next_url)

        user = authenticate(username=username, password=password)
        if user and not next_url:
            login(self.request, user)
            return redirect('user_detail')
        elif user and next_url:
            login(self.request, user)
            return redirect(next_url)
        else:
            return render(self.request, self.template_name, {'form': form})

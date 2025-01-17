from django import forms
from .models import Tweet
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User 

class TweetForm(forms.ModelForm):
    class Meta:
        model=Tweet
        fields=['text','photo']


class UserRegistration(UserCreationForm):
    email = forms.EmailField(max_length=255, help_text='Required. Enter a valid email address.')
    class Meta:
        model=User
        fields=('username','email','password1','password2')
        help_texts={
            'password1': 'Your password must be at least 8 characters long and contain at least one uppercase letter, one lowercase letter, one digit, and one special character.',
            'password2': 'Confirm password must match the entered password.'
        }
from django.shortcuts import render, HttpResponse
from .form import MyForm
import datetime

# import the logging library
import logging

# Get an instance of a logger
logger = logging.getLogger("form_logger")


def ex02(request):
    if request.method == 'POST':
        form = MyForm(request.POST)
        if form.is_valid():
            date = datetime.datetime.now()
            logger.info("Name : {0} || email : {1} || date : {2}".format(form.cleaned_data['name'], form.cleaned_data['email'], date))

            return HttpResponse("Your data have been saved. Thank you!")
    else:
         form = MyForm()
         with open("./info_log.log", 'r') as log:
             data_log = log.readlines()
    return render(request, "ex02/form.html", {'form' : form, 'log_history' : data_log})
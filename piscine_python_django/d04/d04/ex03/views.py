from django.shortcuts import render, HttpResponse

# Create your views here.



def tableau(request):
    list_steps = [float(n) / 50.0 for n in range(50)]
    color = [255 * e for e in list_steps]

    return render(request, "ex03/table.html", {'list_colors':color})
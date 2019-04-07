=====
Ex00
=====

Ex00 is a simple Django app to load images. For each
question, visitors can choose between a fixed number of answers.

Detailed documentation is in the "docs" directory.

Quick start
-----------

1. Add "ex00" to your INSTALLED_APPS setting like this::

    INSTALLED_APPS = [
        ...
        'ex00',
    ]

2. Include the ex00 URLconf in your project urls.py like this::

    path('ex00/', include('ex00.urls')),

3. Run `python manage.py migrate` to create the ex00 models.

4. Start the development server and visit http://127.0.0.1:8000/admin/
   to create a poll (you'll need the Admin app enabled).

5. Visit http://127.0.0.1:8000/ex00/ to participate in the poll.
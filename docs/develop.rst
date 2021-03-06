
********************
Notes for developers
********************

Structure
=========

.. note::

  .. image:: hierarchy.svg
    :width: 800px
    :align: center

Make changes / additions
========================

Be sure to run the verification code in ``develop/``! All existing checks should pass, while new check should be added to check new functionality.

The `Catch <http://catch-lib.net>`_ library has been used to run the checks, it should be used also for all new checks. To compile the checks:

1.  Download and install Catch.

2.  Compile all test cases:

    .. code-block:: bash

      $ mkdir develop/build
      $ cd develop/build
      $ cmake ..
      $ make

3.  Run ``./cppmatTest``.

Python
======

The Python package of this module ``python/cppmat/__init__.py`` is essentially used to allow distribution of the header files that constitute this library through PyPi. In addition a small Python package *cppmat* is provided that allows easy ``setup.py`` formulations of derived packages. These features can also be used when one is just interested in using *pybind11* and one does not intend to use *cppmat* itself.

Create a new release
====================

1.  Update the version number in ``src/cppmat/macros.h``.

2.  Upload the changes to GitHub and create a new release there (with the correct version number).

3.  Upload the package to PyPi:

    .. code-block:: bash

      $ python3 setup.py bdist_wheel --universal
      $ twine upload dist/*


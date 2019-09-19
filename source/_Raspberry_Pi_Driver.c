// Copyright (c) 2014 Adafruit Industries
// Author: Tony DiCola

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
#include <Python.h>

#include "Raspberry_Pi/pi_dht_read.h"

struct module_state {
    PyObject *error;
};

#define GETSTATE(m) ((struct module_state*)PyModule_GetState(m))

// Wrap calling dht_read function and expose it as a DHT.read Python module & function.
static PyObject* Raspberry_Pi_Driver_read(PyObject *self, PyObject *args)
{
	// Parse sensor and pin integer arguments.
    int sensor, pin;
    if (!PyArg_ParseTuple(args, "ii", &sensor, &pin)) {
        return NULL;
    }
    // Call dht_read and return result code, humidity, and temperature.
    float humidity = 0.00, temperature = 0.00;
    int result = pi_dht_read(sensor, pin, &humidity, &temperature);
    return Py_BuildValue("iff", result, humidity, temperature);
}

// Boilerplate python module method list and initialization functions below.

static PyMethodDef module_methods[] = {
    {"read", Raspberry_Pi_Driver_read, METH_VARARGS, "Read DHT sensor value on a Raspberry Pi."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "Raspberry_Pi_Driver",
        NULL,
        sizeof(struct module_state),
        module_methods
};

#define INITERROR return NULL

//PyObject * PyInit_Raspberry_Pi_Driver(void)

//PyMODINIT_FUNC initRaspberry_Pi_Driver(void){
PyMODINIT_FUNC PyInit_Raspberry_Pi_Driver(void){
   PyObject * module = PyModule_Create(&moduledef);
   return module;
}


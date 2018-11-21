/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2018 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */



STATIC const mp_rom_map_elem_t pin_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_init),    MP_ROM_PTR(&pin_init_obj) },
    { MP_ROM_QSTR(MP_QSTR_value),   MP_ROM_PTR(&pin_value_obj) },
    { MP_ROM_QSTR(MP_QSTR_off),     MP_ROM_PTR(&pin_off_obj) },
    { MP_ROM_QSTR(MP_QSTR_on),      MP_ROM_PTR(&pin_on_obj) },
    { MP_ROM_QSTR(MP_QSTR_irq),     MP_ROM_PTR(&pin_irq_obj) },

    // Legacy names as used by pyb.Pin
    { MP_ROM_QSTR(MP_QSTR_low),     MP_ROM_PTR(&pin_off_obj) },
    { MP_ROM_QSTR(MP_QSTR_high),    MP_ROM_PTR(&pin_on_obj) },
    { MP_ROM_QSTR(MP_QSTR_name),    MP_ROM_PTR(&pin_name_obj) },
    { MP_ROM_QSTR(MP_QSTR_names),   MP_ROM_PTR(&pin_names_obj) },
    { MP_ROM_QSTR(MP_QSTR_af_list), MP_ROM_PTR(&pin_af_list_obj) },
    { MP_ROM_QSTR(MP_QSTR_port),    MP_ROM_PTR(&pin_port_obj) },
    { MP_ROM_QSTR(MP_QSTR_pin),     MP_ROM_PTR(&pin_pin_obj) },
    { MP_ROM_QSTR(MP_QSTR_gpio),    MP_ROM_PTR(&pin_gpio_obj) },
    { MP_ROM_QSTR(MP_QSTR_mode),    MP_ROM_PTR(&pin_mode_obj) },
    { MP_ROM_QSTR(MP_QSTR_pull),    MP_ROM_PTR(&pin_pull_obj) },
    { MP_ROM_QSTR(MP_QSTR_af),      MP_ROM_PTR(&pin_af_obj) },

    // class methods
    { MP_ROM_QSTR(MP_QSTR_mapper),  MP_ROM_PTR(&pin_mapper_obj) },
    { MP_ROM_QSTR(MP_QSTR_dict),    MP_ROM_PTR(&pin_map_dict_obj) },
    { MP_ROM_QSTR(MP_QSTR_debug),   MP_ROM_PTR(&pin_debug_obj) },

    // class attributes
    { MP_ROM_QSTR(MP_QSTR_board),   MP_ROM_PTR(&pin_board_pins_obj_type) },
    { MP_ROM_QSTR(MP_QSTR_cpu),     MP_ROM_PTR(&pin_cpu_pins_obj_type) },

    // class constants
    { MP_ROM_QSTR(MP_QSTR_IN),        MP_ROM_INT(GPIO_DIR_MODE_IN) },
    { MP_ROM_QSTR(MP_QSTR_OUT),       MP_ROM_INT(GPIO_DIR_MODE_IN) },
    { MP_ROM_QSTR(MP_QSTR_OPEN_DRAIN), MP_ROM_INT(GPIO_PIN_TYPE_OD) },
    { MP_ROM_QSTR(MP_QSTR_ALT),       MP_ROM_INT(GPIO_DIR_MODE_HW) },
    { MP_ROM_QSTR(MP_QSTR_ALT_OPEN_DRAIN), MP_ROM_INT(GPIO_DIR_MODE_HW) },
    { MP_ROM_QSTR(MP_QSTR_ANALOG),    MP_ROM_INT(GPIO_PIN_TYPE_ANALOG) },
    { MP_ROM_QSTR(MP_QSTR_PULL_UP),   MP_ROM_INT(GPIO_PIN_TYPE_STD_WPU) },
    { MP_ROM_QSTR(MP_QSTR_PULL_DOWN), MP_ROM_INT(GPIO_PIN_TYPE_STD_WPD) },
    { MP_ROM_QSTR(MP_QSTR_PULL_NONE), MP_ROM_INT(GPIO_PIN_TYPE_STD) },
    { MP_ROM_QSTR(MP_QSTR_IRQ_RISING), MP_ROM_INT(GPIO_RISING_EDGE) },
    { MP_ROM_QSTR(MP_QSTR_IRQ_FALLING), MP_ROM_INT(GPIO_FALLING_EDGE) },
    { MP_ROM_QSTR(MP_QSTR_IRQ_BOTH),  MP_ROM_INT(GPIO_BOTH_EDGES) },
    { MP_ROM_QSTR(MP_QSTR_IRQ_HIGH),  MP_ROM_INT(GPIO_HIGH_LEVEL) },
    { MP_ROM_QSTR(MP_QSTR_IRQ_LOW),     MP_ROM_INT(GPIO_LOW_LEVEL) },
    { MP_ROM_QSTR(MP_QSTR_LOW_POWER),     MP_ROM_INT(GPIO_STRENGTH_2MA) },
    { MP_ROM_QSTR(MP_QSTR_MED_POWER),     MP_ROM_INT(GPIO_STRENGTH_4MA) },
    { MP_ROM_QSTR(MP_QSTR_HI_POWER),     MP_ROM_INT(GPIO_STRENGTH_8MA) },
}

STATIC MP_DEFINE_CONST_DICT(pin_locals_dict, pin_locals_dict_table);

cconst mp_obj_type_t pin_type = {
    { &mp_type_type },
    .name = MP_QSTR_Pin,
    .print = pin_print,
    .make_new = pin_make_new,
    .call = pin_call,
    .locals_dict = (mp_obj_t)&pin_locals_dict,
};

STATIC const mp_irq_methods_t pin_irq_methods = {
    .init = pin_irq,
    .enable = pin_irq_enable,
    .disable = pin_irq_disable,
    .flags = pin_irq_flags,
};

STATIC void pin_named_pins_obj_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind) {
    pin_named_pins_obj_t *self = self_in;
    mp_printf(print, "<Pin.%q>", self->name);
}

const mp_obj_type_t pin_board_pins_obj_type = {
    { &mp_type_type },
    .name = MP_QSTR_board,
    .print = pin_named_pins_obj_print,
    .locals_dict = (mp_obj_t)&pin_board_pins_locals_dict,
};

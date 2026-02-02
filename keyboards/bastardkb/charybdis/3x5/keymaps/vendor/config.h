/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#ifdef VIA_ENABLE
/* VIA configuration. */
#    define DYNAMIC_KEYMAP_LAYER_COUNT 8 // 8 capas (0-7)
#endif                                   // VIA_ENABLE

#ifndef __arm__
/* Disable unused features. */
#    define NO_ACTION_ONESHOT
#endif // __arm__

// ========== CONFIGURACIÓN RGB MATRIX ==========
#ifdef RGB_MATRIX_ENABLE
// Brillo reducido
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 80

// Primero eliminar las definiciones existentes, luego redefinir
#    undef RGB_MATRIX_DEFAULT_VAL
#    define RGB_MATRIX_DEFAULT_VAL 80 // Brillo medio

#    undef RGB_MATRIX_DEFAULT_SPD
#    define RGB_MATRIX_DEFAULT_SPD 15 // Velocidad media de animación

// Modo por defecto: luz blanca suave con breathing (respiración)
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_BREATHING
#    define RGB_MATRIX_DEFAULT_HUE 0 // Hue 0
#    define RGB_MATRIX_DEFAULT_SAT 0 // Saturación 0 = blanco puro

// Habilitar solo los efectos que necesitamos
#    define ENABLE_RGB_MATRIX_BREATHING   // Respiración suave (para capa base)
#    define ENABLE_RGB_MATRIX_SOLID_COLOR // Color sólido (para capas)

// Sincronización para teclados split
#    define CHARYBDIS_CONFIG_SYNC
#endif // RGB_MATRIX_ENABLE

/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// ========== AUTO POINTER LAYER ==========
// Se activa automáticamente al mover el trackball
#    define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
// Aumentado a 1500ms: da más tiempo antes de desactivar la capa pointer,
// evitando que se cicle activar/desactivar cuando haces movimientos cortos
#    define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1500
// Subido a 8: requiere un movimiento más deliberado para activar la capa.
// Con 5 se activaba con cualquier roce accidental.
#    define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8

// ========== DPI BASE ==========
// Bajado a 800. Con el trackball pequeño del Nano, 2000 causaba que
// movimientos pequeños resultaran en saltos grandes del cursor.
// 800 te da control fino; puedes subir con DPI_MOD si necesitas velocidad.
#    define CHARYBDIS_MINIMUM_DEFAULT_DPI 2000
// Paso de 200 DPI para ajustar con DPI_MOD (toca la tecla en LAYER_POINTER)
#    define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 200

// ========== VELOCITY PROCESSING (clave para movimiento fluido) ==========
// Esto reemplaza la aceleración agresiva. En lugar de un factor fijo que
// "traga" movimientos pequeños, procesa la velocidad de forma suave:
// movimientos lentos → cursor lento y preciso
// movimientos rápidos → cursor rápido
// Es lo más cercano a un mouse convencional sobre un trackball.
#    define CHARYBDIS_POINTER_VELOCITY_PROCESSING_ENABLE
// Factor de suavizado. Valores más altos = más suave pero más latencia.
// 20 es un buen punto medio para el Nano.
#    define CHARYBDIS_POINTER_VELOCITY_SLOWING_FACTOR 12

// ========== SNIPING (modo precisión) ==========
// DPI que se activa al presionar SNIPING en LAYER_POINTER.
// 300 DPI te da control muy fino para trabajo detallado.
#    define CHARYBDIS_MINIMUM_SNIPING_DPI 300
#    define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 100

// ========== DRAG SCROLL ==========
// Bajado a 3. Con 6 el scroll tenía demasiado lag antes de responder.
#    define CHARYBDIS_DRAGSCROLL_BUFFER_SIZE 3
// Mantener la inversión de X si te funcionaba bien
#    define CHARYBDIS_DRAGSCROLL_REVERSE_X
// #    define CHARYBDIS_DRAGSCROLL_REVERSE_Y
#endif // POINTING_DEVICE_ENABLE

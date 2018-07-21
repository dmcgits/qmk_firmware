#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "hal.h"
#include "timer.h"
#include "wait.h"
#include "printf.h"
#include "backlight.h"
#include "matrix.h"


/* Anne Pro 60%
 *
 * Column pins are input with internal pull-down. 
 * Row pins are output and strobe with high.
 * Key is high or 1 when it turns on.
 *
 *     col: { PA5, PA6, PA7, PB0, PB1, PB12, PB13, PB14, PA8, PA9, PA15, PB3, PB4, PB5 }
 *     row: { PB9, PB8, PB7, PB6, PA0 }
 */
/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_COLS];
static bool debouncing = false;
static uint16_t debouncing_time = 0;

__attribute__ ((weak))
	void matrix_init_user(void) {}

__attribute__ ((weak))
	void matrix_scan_user(void) {}

__attribute__ ((weak))
	void matrix_init_kb(void) {
		matrix_init_user();
	}

__attribute__ ((weak))
	void matrix_scan_kb(void) {
		matrix_scan_user();
	}

void matrix_init(void) {
	printf("matrix init\n");
	//debug_matrix = true;

	/* Column(sense) */
	palSetPadMode(GPIOA, 5,  PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOA, 6,  PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOA, 7,  PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOB, 0, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOB, 1, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOB, 12,  PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOB, 13,  PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOB, 14,  PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOA, 8,  PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOA, 9,  PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOA, 15, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOB, 3, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOB, 4, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOB, 5,  PAL_MODE_OUTPUT_PUSHPULL);

	/* Row(strobe) */
	palSetPadMode(GPIOB, 9,  PAL_MODE_INPUT_PULLDOWN);
	palSetPadMode(GPIOB, 8,  PAL_MODE_INPUT_PULLDOWN);
	palSetPadMode(GPIOB, 7,  PAL_MODE_INPUT_PULLDOWN);
	palSetPadMode(GPIOB, 6,  PAL_MODE_INPUT_PULLDOWN);
	palSetPadMode(GPIOA, 0,  PAL_MODE_INPUT_PULLDOWN);

	memset(matrix, 0, MATRIX_ROWS);
	memset(matrix_debouncing, 0, MATRIX_COLS);

	/* Setup capslock */
	// palSetPadMode(GPIOB, 7,  PAL_MODE_OUTPUT_PUSHPULL);
	// palClearPad(GPIOB, 7);

	matrix_init_quantum();
}

uint8_t matrix_scan(void) {
	for (int col = 0; col < MATRIX_COLS; col++) {
		matrix_row_t data = 0;

	 // strobe col { PA5, PA6, PA7, PB0, PB1, PB12, PB13, PB14, PA8, PA9, PA15, PB3, PB4, PB5 }
	 switch (col) {
		 case 0: palSetPad(GPIOA, 5); break; 
		 case 1: palSetPad(GPIOA, 6); break; 
		 case 2: palSetPad(GPIOA, 7); break; 
		 case 3: palSetPad(GPIOB, 0); break; 
		 case 4: palSetPad(GPIOB, 1); break; 
		 case 5: palSetPad(GPIOB, 12); break; 
		 case 6: palSetPad(GPIOB, 13); break; 
		 case 7: palSetPad(GPIOB, 14); break; 
		 case 8: palSetPad(GPIOA, 8); break; 
		 case 9: palSetPad(GPIOA, 9); break; 
		 case 10: palSetPad(GPIOA, 15); break; 
		 case 11: palSetPad(GPIOB, 3); break; 
		 case 12: palSetPad(GPIOB, 4); break; 
		 case 13: palSetPad(GPIOB, 5); break; 
	 }

	 // need wait to settle pin state
	 wait_us(20);

	 // read row data { PB9, PB8, PB7, PB6, PA0 }
	 data = (
			 (palReadPad(GPIOB, 9) << 0 ) |
			 (palReadPad(GPIOB, 8) << 1 ) |
			 (palReadPad(GPIOB, 7) << 2 ) |
			 (palReadPad(GPIOB, 6) << 3 ) |
			 (palReadPad(GPIOA, 0) << 4 )
			);

	 // unstrobe col { PA5, PA6, PA7, PB0, PB1, PB12, PB13, PB14, PA8, PA9, PA15, PB3, PB4, PB5 }
	 switch (col) {
		 case 0: palClearPad(GPIOA, 5); break; 
		 case 1: palClearPad(GPIOA, 6); break; 
		 case 2: palClearPad(GPIOA, 7); break; 
		 case 3: palClearPad(GPIOB, 0); break; 
		 case 4: palClearPad(GPIOB, 1); break; 
		 case 5: palClearPad(GPIOB, 12); break; 
		 case 6: palClearPad(GPIOB, 13); break; 
		 case 7: palClearPad(GPIOB, 14); break; 
		 case 8: palClearPad(GPIOA, 8); break; 
		 case 9: palClearPad(GPIOA, 9); break; 
		 case 10: palClearPad(GPIOA, 15); break; 
		 case 11: palClearPad(GPIOB, 3); break; 
		 case 12: palClearPad(GPIOB, 4); break; 
		 case 13: palClearPad(GPIOB, 5); break; 
	 }

	 if (matrix_debouncing[col] != data) {
		 matrix_debouncing[col] = data;
		 debouncing = true;
		 debouncing_time = timer_read();
	 }
	}
	if (debouncing && timer_elapsed(debouncing_time) > DEBOUNCE) {
		for (int row = 0; row < MATRIX_ROWS; row++) {
			matrix[row] = 0;
			for (int col = 0; col < MATRIX_COLS; col++) {
				matrix[row] |= ((matrix_debouncing[col] & (1 << row) ? 1 : 0) << col);
			}
		}
		debouncing = false;
	}

	matrix_scan_quantum();

	return 1;
}

bool matrix_is_on(uint8_t row, uint8_t col) {
	return (matrix[row] & (1<<col));
}

matrix_row_t matrix_get_row(uint8_t row) {
	return matrix[row];
}

void matrix_print(void) {
	printf("\nr/c 01234567\n");
	for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
		printf("%X0: ", row);
		matrix_row_t data = matrix_get_row(row);
		for (int col = 0; col < MATRIX_COLS; col++) {
			if (data & (1<<col))
				printf("1");
			else
				printf("0");
		}
		printf("\n");
	}
}

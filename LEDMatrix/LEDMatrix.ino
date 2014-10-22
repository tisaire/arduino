// 2-dimensional array of row pin numbers:
const int rownum[8] = {
10,12,15,17,2,4,6,8 };
// 2-dimensional array of column pin numbers:
const int colnum[8] = {
11,14,16,18,3,5,7,9  };

float timeCount = 0;

int h[8][8] = {
{0,0,1,0,0,0,1,0},
{0,0,1,0,0,0,1,0},
{0,0,1,0,0,0,1,0},
{0,0,1,1,1,1,1,0},
{0,0,1,1,1,1,1,0},
{0,0,1,0,0,0,1,0},
{0,0,1,0,0,0,1,0},
{0,0,1,0,0,0,1,0}};

int e[8][8] = {
{0,0,1,1,1,1,1,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,1,1,1,0},
{0,0,0,0,1,1,1,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0},
{0,0,1,1,1,1,1,0}};

int l[8][8] = {
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,1,0},
{0,0,1,1,1,1,1,0}};

int o[8][8] = {
{0,0,0,1,1,1,0,0},
{0,0,1,0,0,0,1,0},
{0,0,1,0,0,0,1,0},
{0,0,1,0,0,0,1,0},
{0,0,1,0,0,0,1,0},
{0,0,1,0,0,0,1,0},
{0,0,1,0,0,0,1,0},
{0,0,0,1,1,1,0,0}};

int smile[8][8] = {
{0,0,0,0,0,0,0,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,1,0},
{0,0,1,0,0,1,0,0},
{0,0,0,1,1,0,0,0}};

int blank[8][8] = {
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}};

void setup() {
	Serial.begin(9600);
	// initialize the I/O pins as outputs:

	// iterate over the pins:
	for (int thisPin = 0; thisPin &lt; 8; thisPin++) {
		// initialize the output pins:
		pinMode(colnum[thisPin], OUTPUT);
		pinMode(rownum[thisPin], OUTPUT);
		// take the col pins (i.e. the cathodes) high to ensure that
		// the LEDS are off:
		digitalWrite(colnum[thisPin], LOW);
		digitalWrite(rownum[thisPin], HIGH);
	}

}

void loop() {
	// This could be rewritten to not use a delay, which would make it appear brighter
	delay(5);
	timeCount += 1;
	if(timeCount &lt; 200) {
		drawScreen(h);
	} else if (timeCount &lt; 230) {
		// do nothing
	} else if (timeCount &lt; 400) {
		drawScreen(e);
	} else if (timeCount &lt; 430) {
		// nothing
	} else if (timeCount &lt; 600) {
		drawScreen(l);
	} else if (timeCount &lt; 630) {
		// nothing
	} else if (timeCount &lt; 800) {
		drawScreen(l);
	} else if (timeCount &lt; 830) {
		// nothing
	} else if (timeCount &lt; 1000) {
		drawScreen(o);
	} else if (timeCount &lt; 1030) {
		// nothing
	} else if (timeCount &lt; 1200) {
		drawScreen(smile);
	} else if (timeCount &lt; 1230) {
		// nothing
	} else {
		// back to the start
		timeCount = 0;
	}
}

int row(int i) {
	if(i == 1) {
		return 10;
	} else if (i == 2) {
		return 12;
	} else if (i == 3) {
		return 15;
	} else if (i == 4) {
		return 17;
	} else if (i == 5) {
		return 2;
	} else if (i == 6) {
		return 4;
	} else if (i == 7) {
		return 6;
	} else if (i == 8) {
		return 8;
	}
}

int col(int i) {
	if(i == 1) {
		return 11;
	} else if (i == 2) {
		return 14;
	} else if (i == 3) {
		return 16;
	} else if (i == 4) {
		return 18;
	} else if (i == 5) {
		return 3;
	} else if (i == 6) {
		return 5;
	} else if (i == 7) {
		return 7;
	} else if (i == 8) {
		return 9;
	}
}

void drawScreen(int character[8][8]) {
	for(int j = 0; j &lt; 8; j++) {
		// Turn the row on
		int rowNumber = j + 1;
		digitalWrite(row(rowNumber), LOW);
		for (int k = 0; k &lt; 8; k++) {
			// draw some letter bits
			int columnNumber = k + 1;
			if(character[j][k] == 1) {
				digitalWrite(col(columnNumber), HIGH);
			}

			digitalWrite(col(columnNumber), LOW);
		}
		digitalWrite(row(rowNumber), HIGH);
	}
}
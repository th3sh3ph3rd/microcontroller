interface PS2 {

	// IOs initialisieren, IRQ aktivieren
	command void init(void);

	// character empfangen
	async event void receivedChar(uint8_t chr);

}

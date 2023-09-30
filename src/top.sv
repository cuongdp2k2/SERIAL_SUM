module top (
	// input
	input logic CLOCK_27 ,
	
	// output
	output logic LCD_EN  , LCD_RS , LCD_ON , LCD_RW ,
	output logic [7:0] LCD_DATA
);
	assign LCD_ON = 1'b1;
	assign LCD_RW = 1'b0;
	test_LCD LCD_display (
		.clk(CLOCK_27) ,
		.lcd_e (LCD_EN) ,
		.lcd_rs (LCD_RS) ,
		.data(LCD_DATA)
	);
endmodule : top
module test_LCD(
input clk,
output reg lcd_e, lcd_rs,
output reg [7:0] data
);
//////////////////////////////////////////////////////
//preset lcd write
integer j = 1;
logic [7:0] tmp;
reg [1:9][7:0] Datas ;
always @(posedge clk) begin
	Datas[1] = 8'h38; //-- control instruction : configure - 2 lines, 5x7 matrix --
	Datas[2] = 8'h0C; //-- control instruction : Display on, cursor off --
	Datas[3] = 8'h06; //-- control instruction : Increment cursor : shift cursor to
	Datas[4] = 8'h01; //-- control instruction : clear display screen --
	Datas[5] = 8'h80; //-- control instruction : force cursor to begin at first
	Datas[6] = "0" ;
	Datas[7] = "x" ;
	Datas[8] = {4'b0,tmp[7:4]} + 8'h30 ;
	Datas[9] = {4'b0,tmp[3:0]} + 8'h30 ;
	end

__8b_add adder1 (
	.A_i(8'h3C),
	.B_i(8'h3C),
	.C_o(tmp)
);
	
integer i = 0; //
always @(posedge clk) begin
//-- Delay for writing data
if (i <= 1000000) begin
	i = i + 1; lcd_e = 1;
	data = Datas[j];
end
else if (i > 1000000 & i < 2000000) begin

	i = i + 1; lcd_e = 0;
end
else if (i == 2000000) begin
	j = j + 1; i = 0;
end
else i = 0;
//-- LCD_RS signal should be set to 0 for writing commands and to 1 for writing data
if (j <= 5 )
	lcd_rs = 0;
else if (j > 5 & j< 10)
	lcd_rs = 1;
else if (j == 10)
	lcd_rs = 0;

else if (j > 10) begin
	lcd_rs = 1;
	j = 5;
end
else lcd_rs = 1;

//else
//if (j > 27) begin
//	lcd_rs = 1;
//	j = 5;
//end
end
endmodule
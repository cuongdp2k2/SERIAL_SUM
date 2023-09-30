module hex_to_dec (
    input logic [15:0] hex_i,
    output logic [15:0] dec [4:0]
);
logic [15:0] wire_1[4:0];
    assign wire_1[0] = hex_i % 10;
    assign wire_1[1] = (hex_i/10)%10;
    assign wire_1[2] = (hex_i/100)%10;
    assign wire_1[3] = (hex_i/1000)%10;
    assign wire_1[4] = (hex_i/10000)%10;
    assign dec = wire_1;
endmodule

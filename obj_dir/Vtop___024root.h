// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk_i,0,0);
    VL_IN8(rst_ni,0,0);
    VL_IN8(data_i,7,0);
    VL_IN8(n_i,7,0);
    VL_OUT8(done_o,0,0);
    CData/*7:0*/ top__DOT__sum_module__DOT__count_reg;
    CData/*0:0*/ top__DOT__sum_module__DOT__done_wire;
    CData/*7:0*/ top__DOT__sum_module__DOT__count_wire;
    CData/*0:0*/ __Vclklast__TOP__clk_i;
    VL_OUT16(sum_o,15,0);
    SData/*15:0*/ top__DOT__sum_module__DOT__sum_reg;
    SData/*15:0*/ top__DOT__sum_module__DOT__add_wire;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

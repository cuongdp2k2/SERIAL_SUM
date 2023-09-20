// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___settle__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__sum_module__DOT__count_wire = vlSelf->top__DOT__sum_module__DOT__count_reg;
    if ((0U == (IData)(vlSelf->top__DOT__sum_module__DOT__count_reg))) {
        vlSelf->top__DOT__sum_module__DOT__done_wire = 1U;
        vlSelf->done_o = 1U;
        vlSelf->top__DOT__sum_module__DOT__out_wire 
            = vlSelf->top__DOT__sum_module__DOT__sum_reg;
    } else {
        vlSelf->top__DOT__sum_module__DOT__done_wire = 0U;
        vlSelf->done_o = 0U;
        vlSelf->top__DOT__sum_module__DOT__out_wire 
            = vlSelf->top__DOT__sum_module__DOT__out_reg;
    }
    if (vlSelf->en_i) {
        vlSelf->top__DOT__sum_module__DOT__data_in 
            = (0xffU & (IData)(vlSelf->data_i));
        vlSelf->sum_o = (0xffffU & (IData)(vlSelf->top__DOT__sum_module__DOT__out_wire));
    } else {
        vlSelf->top__DOT__sum_module__DOT__data_in = 0U;
        vlSelf->sum_o = 0U;
    }
    vlSelf->top__DOT__sum_module__DOT__add_wire = (0xffffU 
                                                   & ((IData)(vlSelf->top__DOT__sum_module__DOT__sum_reg) 
                                                      + 
                                                      ((IData)(vlSelf->rst_ni)
                                                        ? 
                                                       ((0U 
                                                         == (IData)(vlSelf->top__DOT__sum_module__DOT__count_reg))
                                                         ? 0U
                                                         : 
                                                        ((0xff00U 
                                                          & ((- (IData)(
                                                                        (1U 
                                                                         & ((IData)(vlSelf->top__DOT__sum_module__DOT__data_in) 
                                                                            >> 7U)))) 
                                                             << 8U)) 
                                                         | (IData)(vlSelf->top__DOT__sum_module__DOT__data_in)))
                                                        : 0U)));
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
}

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk_i = VL_RAND_RESET_I(1);
    vlSelf->rst_ni = VL_RAND_RESET_I(1);
    vlSelf->en_i = VL_RAND_RESET_I(1);
    vlSelf->data_i = VL_RAND_RESET_I(8);
    vlSelf->n_i = VL_RAND_RESET_I(8);
    vlSelf->done_o = VL_RAND_RESET_I(1);
    vlSelf->sum_o = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__sum_module__DOT__count_reg = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__sum_module__DOT__sum_reg = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__sum_module__DOT__out_reg = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__sum_module__DOT__done_wire = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sum_module__DOT__data_in = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__sum_module__DOT__out_wire = VL_RAND_RESET_I(16);
    vlSelf->top__DOT__sum_module__DOT__count_wire = VL_RAND_RESET_I(8);
    vlSelf->top__DOT__sum_module__DOT__add_wire = VL_RAND_RESET_I(16);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}

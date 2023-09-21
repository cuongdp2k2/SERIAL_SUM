// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___combo__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__sum_module__DOT__data_in = ((IData)(vlSelf->en_i)
                                                   ? 
                                                  (0xffU 
                                                   & VL_EXTENDS_II(32,8, (IData)(vlSelf->data_i)))
                                                   : 0U);
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Body
    if (vlSelf->rst_ni) {
        vlSelf->top__DOT__sum_module__DOT__out_reg 
            = (0xffffU & (IData)(vlSelf->top__DOT__sum_module__DOT__out_wire));
        vlSelf->top__DOT__sum_module__DOT__sum_reg 
            = ((0U == (IData)(vlSelf->top__DOT__sum_module__DOT__count_reg))
                ? 0U : (0xffffU & (IData)(vlSelf->top__DOT__sum_module__DOT__add_wire)));
        vlSelf->top__DOT__sum_module__DOT__count_reg 
            = (0xffU & ((IData)(vlSelf->top__DOT__sum_module__DOT__done_wire)
                         ? ((IData)(vlSelf->en_i) ? 
                            (0xffU & (IData)(vlSelf->n_i))
                             : 0U) : ((IData)(vlSelf->top__DOT__sum_module__DOT__count_wire) 
                                      - (IData)(1U))));
    } else {
        vlSelf->top__DOT__sum_module__DOT__out_reg = 0U;
        vlSelf->top__DOT__sum_module__DOT__sum_reg = 0U;
        vlSelf->top__DOT__sum_module__DOT__count_reg = 0U;
    }
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
}

VL_INLINE_OPT void Vtop___024root___combo__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__1\n"); );
    // Body
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
    vlSelf->sum_o = ((IData)(vlSelf->en_i) ? (0xffffU 
                                              & (IData)(vlSelf->top__DOT__sum_module__DOT__out_wire))
                      : 0U);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    Vtop___024root___combo__TOP__0(vlSelf);
    if (((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i)))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    Vtop___024root___combo__TOP__1(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->en_i & 0xfeU))) {
        Verilated::overWidthError("en_i");}
}
#endif  // VL_DEBUG

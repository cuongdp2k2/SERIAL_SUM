// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__sum_module__DOT__count_reg),8);
        bufp->chgSData(oldp+1,(vlSelf->top__DOT__sum_module__DOT__sum_reg),16);
        bufp->chgBit(oldp+2,((0U == (IData)(vlSelf->top__DOT__sum_module__DOT__count_reg))));
    }
    bufp->chgBit(oldp+3,(vlSelf->clk_i));
    bufp->chgBit(oldp+4,(vlSelf->rst_ni));
    bufp->chgCData(oldp+5,(vlSelf->data_i),8);
    bufp->chgCData(oldp+6,(vlSelf->n_i),8);
    bufp->chgBit(oldp+7,(vlSelf->done_o));
    bufp->chgSData(oldp+8,(vlSelf->sum_o),16);
    bufp->chgSData(oldp+9,(((IData)(vlSelf->rst_ni)
                             ? ((0U == (IData)(vlSelf->top__DOT__sum_module__DOT__count_reg))
                                 ? 0U : (0xffffU & 
                                         ((0xff00U 
                                           & ((- (IData)(
                                                         (1U 
                                                          & ((IData)(vlSelf->data_i) 
                                                             >> 7U)))) 
                                              << 8U)) 
                                          | (IData)(vlSelf->data_i))))
                             : 0U)),16);
    bufp->chgSData(oldp+10,((0xffffU & ((IData)(vlSelf->top__DOT__sum_module__DOT__sum_reg) 
                                        + ((IData)(vlSelf->rst_ni)
                                            ? ((0U 
                                                == (IData)(vlSelf->top__DOT__sum_module__DOT__count_reg))
                                                ? 0U
                                                : (
                                                   (0xff00U 
                                                    & ((- (IData)(
                                                                  (1U 
                                                                   & ((IData)(vlSelf->data_i) 
                                                                      >> 7U)))) 
                                                       << 8U)) 
                                                   | (IData)(vlSelf->data_i)))
                                            : 0U)))),16);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}

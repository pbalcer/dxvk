#pragma once

#include <mutex>
#include <unordered_map>

#include "dxgi_format.h"
#include "dxgi_interfaces.h"
#include "dxgi_output.h"

namespace dxvk {
  
  class DxgiFactory;
  class DxgiOutput;
  
  class DxgiAdapter : public DxgiObject<IDXGIVkAdapter> {
    
  public:
    
    DxgiAdapter(
            DxgiFactory*      factory,
      const Rc<DxvkAdapter>&  adapter);
    ~DxgiAdapter();
    
    HRESULT STDMETHODCALLTYPE QueryInterface(
            REFIID                    riid,
            void**                    ppvObject) final;
    
    HRESULT STDMETHODCALLTYPE GetParent(
            REFIID                    riid,
            void**                    ppParent) final;
    
    HRESULT STDMETHODCALLTYPE CheckInterfaceSupport(
            REFGUID                   InterfaceName,
            LARGE_INTEGER*            pUMDVersion) final;
    
    HRESULT STDMETHODCALLTYPE EnumOutputs(
            UINT                      Output,
            IDXGIOutput**             ppOutput) final;
    
    HRESULT STDMETHODCALLTYPE GetDesc(
            DXGI_ADAPTER_DESC*        pDesc) final;
    
    HRESULT STDMETHODCALLTYPE GetDesc1(
            DXGI_ADAPTER_DESC1*       pDesc) final;
    
    HRESULT STDMETHODCALLTYPE GetDesc2(
            DXGI_ADAPTER_DESC2*       pDesc) final;
    
    HRESULT STDMETHODCALLTYPE QueryVideoMemoryInfo(
            UINT                          NodeIndex,
            DXGI_MEMORY_SEGMENT_GROUP     MemorySegmentGroup,
            DXGI_QUERY_VIDEO_MEMORY_INFO* pVideoMemoryInfo) final;

    HRESULT STDMETHODCALLTYPE SetVideoMemoryReservation(
            UINT                          NodeIndex,
            DXGI_MEMORY_SEGMENT_GROUP     MemorySegmentGroup,
            UINT64                        Reservation) final;
    
    HRESULT STDMETHODCALLTYPE RegisterHardwareContentProtectionTeardownStatusEvent(
            HANDLE                        hEvent,
            DWORD*                        pdwCookie) final;

    HRESULT STDMETHODCALLTYPE RegisterVideoMemoryBudgetChangeNotificationEvent(
            HANDLE                        hEvent,
            DWORD*                        pdwCookie) final;
    
    void STDMETHODCALLTYPE UnregisterHardwareContentProtectionTeardownStatus(
            DWORD                         dwCookie) final;

    void STDMETHODCALLTYPE UnregisterVideoMemoryBudgetChangeNotification(
            DWORD                         dwCookie) final;

    Rc<DxvkAdapter> STDMETHODCALLTYPE GetDXVKAdapter() final;
    
    HRESULT STDMETHODCALLTYPE CreateDevice(
            IDXGIObject*              pContainer,
      const DxvkDeviceFeatures*       pFeatures,
            IDXGIVkDevice**           ppDevice) final;
    
    DXGI_VK_FORMAT_INFO STDMETHODCALLTYPE LookupFormat(
            DXGI_FORMAT               Format,
            DXGI_VK_FORMAT_MODE       Mode) final;
    
    DXGI_VK_FORMAT_FAMILY STDMETHODCALLTYPE LookupFormatFamily(
            DXGI_FORMAT               Format,
            DXGI_VK_FORMAT_MODE       Mode) final;
    
    HRESULT GetOutputFromMonitor(
            HMONITOR                  Monitor,
            IDXGIOutput**             ppOutput);
    
    HRESULT GetOutputData(
            HMONITOR                  Monitor,
            DXGI_VK_OUTPUT_DATA*      pOutputData);
    
    HRESULT SetOutputData(
            HMONITOR                  Monitor,
      const DXGI_VK_OUTPUT_DATA*      pOutputData);
    
  private:
    
    using OutputMap = std::unordered_map<HMONITOR, DXGI_VK_OUTPUT_DATA>;
    
    Com<DxgiFactory>  m_factory;
    Rc<DxvkAdapter>   m_adapter;
    
    DXGIVkFormatTable m_formats;
    UINT64            m_memReservation[2] = { 0, 0 };
    
    std::mutex        m_outputMutex;
    OutputMap         m_outputData;
    
  };

}

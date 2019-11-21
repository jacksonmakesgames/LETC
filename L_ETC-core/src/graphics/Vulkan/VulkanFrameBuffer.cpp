#include "VulkanFrameBuffer.h"

namespace letc {namespace graphics {

	VulkanFrameBuffer::VulkanFrameBuffer(const VkDevice& device, const std::vector<VkImageView>& swapChainImageViews, const VkRenderPass& renderPass, const VkExtent2D& swapChainExtent){
		m_swapChainFramebuffers.resize(swapChainImageViews.size());
		m_device = device;


		for (size_t i = 0; i < swapChainImageViews.size(); i++) {
			VkImageView attachments[] = {
				swapChainImageViews[i]
			};

			VkFramebufferCreateInfo framebufferInfo = {};
			framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
			framebufferInfo.renderPass = renderPass;
			framebufferInfo.attachmentCount = 1;
			framebufferInfo.pAttachments = attachments;
			framebufferInfo.width = swapChainExtent.width;
			framebufferInfo.height = swapChainExtent.height;
			framebufferInfo.layers = 1;

			if (vkCreateFramebuffer(m_device, &framebufferInfo, nullptr, &m_swapChainFramebuffers[i]) != VK_SUCCESS) {
				throw std::runtime_error("failed to create framebuffer!");
			}
		}
	}

	VulkanFrameBuffer::~VulkanFrameBuffer(){
		for (auto framebuffer : m_swapChainFramebuffers) {
			vkDestroyFramebuffer(m_device, framebuffer, nullptr);
		}
	}

}}
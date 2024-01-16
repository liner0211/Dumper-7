#pragma once
#include <string>

/* Should be renamed to just "Settings.h" once the legacy generator was removed */

namespace SettingsRewrite
{
	namespace Generator
	{
		//Auto generated if no override is provided
		inline std::string GameName = "";
		inline std::string GameVersion = "";

		inline constexpr const char* SDKGenerationPath = "C:/Dumper-7";
	}

	namespace CppGenerator
	{
		//No prefix for files -> FilePrefix = ""
		constexpr const char* FilePrefix = "";

		//No seperate namespace for SDK -> SDKNamespaceName = nullptr
		constexpr const char* SDKNamespaceName = "SDK";

		//No seperate namespace for Params -> ParamNamespaceName = nullptr
		constexpr const char* ParamNamespaceName = "Params";

		//Do not XOR strings -> XORString = nullptr
		constexpr const char* XORString = nullptr;

		//Customizable part of Cpp code to allow for a custom 'uintptr_t InSDKUtils::GetImageBase()' function
		constexpr const char* GetImageBaseFuncBody = 
R"(	{
		reinterpret_cast<uintptr_t>(GetModuleHandle(0));
	}
)";
		//Customizable part of Cpp code to allow for a custom 'InSDKUtils::CallGameFunction' function
		constexpr const char* CallGameFunction =
R"(
	template<typename FuncType, typename... ParamTypes>
	requires std::invocable<FuncType, ParamTypes...>
	inline auto CallGameFunction(FuncType Function, ParamTypes&&... Args)
	{
		return Function(std::forward<ParamTypes>(Args)...);
	}
)";
	}

	/* Not implemented */
	namespace Debug
	{
		inline constexpr bool bGenerateAssertionFile = false;
		inline constexpr bool bLimitAssertionsToEngienPackage = true;

		// Recommended
		inline constexpr bool bGenerateAssertionsForPredefinedMembers = true;
	}

	// Do not change manually
	namespace Internal
	{
		// UEEnum::Names
		inline bool bIsEnumNameOnly = false;

		inline bool bUseFProperty = false;

		inline bool bUseNamePool = false;

		inline bool bUseCasePreservingName = false;
		inline bool bUseUoutlineNumberName = false;

		inline bool bUseMaskForFieldOwner = false;

		inline std::string MainGamePackageName;
	}
}
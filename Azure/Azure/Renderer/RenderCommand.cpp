#include "azphc.h"
#include "RenderCommand.h"

namespace Azure
{
    Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}//Azure
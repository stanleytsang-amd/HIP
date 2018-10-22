#include "CUDA2HIP.h"

// Map of all functions
const std::map<llvm::StringRef, hipCounter> CUDA_DNN_FUNCTION_MAP{

  {"cudnnGetVersion",                                     {"hipdnnGetVersion",                                     CONV_VERSION, API_DNN}},
  {"cudnnGetCudartVersion",                               {"hipdnnGetCudartVersion",                               CONV_VERSION, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnQueryRuntimeError",                              {"hipdnnQueryRuntimeError",                              CONV_VERSION, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetProperty",                                    {"hipdnnGetProperty",                                    CONV_VERSION, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetErrorString",                                 {"hipdnnGetErrorString",                                 CONV_ERROR, API_DNN}},
  {"cudnnIm2Col",                                         {"hipdnnIm2Col",                                         CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnCreate",                                         {"hipdnnCreate",                                         CONV_MATH_FUNC, API_DNN}},
  {"cudnnDestroy",                                        {"hipdnnDestroy",                                        CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetStream",                                      {"hipdnnSetStream",                                      CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetStream",                                      {"hipdnnGetStream",                                      CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetCallback",                                    {"hipdnnSetCallback",                                    CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetCallback",                                    {"hipdnnGetCallback",                                    CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},

  // cuDNN Tensor functions
  {"cudnnCreateTensorDescriptor",                         {"hipdnnCreateTensorDescriptor",                         CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetTensor4dDescriptor",                          {"hipdnnSetTensor4dDescriptor",                          CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetTensor4dDescriptorEx",                        {"hipdnnSetTensor4dDescriptorEx",                        CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetTensor4dDescriptor",                          {"hipdnnGetTensor4dDescriptor",                          CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetTensorNdDescriptor",                          {"hipdnnSetTensorNdDescriptor",                          CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetTensorNdDescriptorEx",                        {"hipdnnSetTensorNdDescriptorEx",                        CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetTensorNdDescriptor",                          {"hipdnnGetTensorNdDescriptor",                          CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetTensorSizeInBytes",                           {"hipdnnGetTensorSizeInBytes",                           CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnDestroyTensorDescriptor",                        {"hipdnnDestroyTensorDescriptor",                        CONV_MATH_FUNC, API_DNN}},
  {"cudnnTransformTensor",                                {"hipdnnTransformTensor",                                CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnAddTensor",                                      {"hipdnnAddTensor",                                      CONV_MATH_FUNC, API_DNN}},
  {"cudnnCreateOpTensorDescriptor",                       {"hipdnnCreateOpTensorDescriptor",                       CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetOpTensorDescriptor",                          {"hipdnnSetOpTensorDescriptor",                          CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetOpTensorDescriptor",                          {"hipdnnGetOpTensorDescriptor",                          CONV_MATH_FUNC, API_DNN}},
  {"cudnnDestroyOpTensorDescriptor",                      {"hipdnnDestroyOpTensorDescriptor",                      CONV_MATH_FUNC, API_DNN}},
  {"cudnnOpTensor",                                       {"hipdnnOpTensor",                                       CONV_MATH_FUNC, API_DNN}},

  // cuDNN Reduce Tensor functions
  {"cudnnCreateReduceTensorDescriptor",                   {"hipdnnCreateReduceTensorDescriptor",                   CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetReduceTensorDescriptor",                      {"hipdnnSetReduceTensorDescriptor",                      CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetReduceTensorDescriptor",                      {"hipdnnGetReduceTensorDescriptor",                      CONV_MATH_FUNC, API_DNN}},
  {"cudnnDestroyReduceTensorDescriptor",                  {"hipdnnDestroyReduceTensorDescriptor",                  CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetReductionIndicesSize",                        {"hipdnnGetReductionIndicesSize",                        CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetReductionWorkspaceSize",                      {"hipdnnGetReductionWorkspaceSize",                      CONV_MATH_FUNC, API_DNN}},
  {"cudnnReduceTensor",                                   {"hipdnnReduceTensor",                                   CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetTensor",                                      {"hipdnnSetTensor",                                      CONV_MATH_FUNC, API_DNN}},
  {"cudnnScaleTensor",                                    {"hipdnnScaleTensor",                                    CONV_MATH_FUNC, API_DNN}},

  // cuDNN Filter functions
  {"cudnnCreateFilterDescriptor",                         {"hipdnnCreateFilterDescriptor",                         CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetFilter4dDescriptor",                          {"hipdnnSetFilter4dDescriptor",                          CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetFilter4dDescriptor",                          {"hipdnnGetFilter4dDescriptor",                          CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSetFilterNdDescriptor",                          {"hipdnnSetFilterNdDescriptor",                          CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetFilterNdDescriptor",                          {"hipdnnGetFilterNdDescriptor",                          CONV_MATH_FUNC, API_DNN}},
  {"cudnnDestroyFilterDescriptor",                        {"hipdnnDestroyFilterDescriptor",                        CONV_MATH_FUNC, API_DNN}},

  // cuDNN Convolution functions
  {"cudnnCreateConvolutionDescriptor",                    {"hipdnnCreateConvolutionDescriptor",                    CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetConvolutionMathType",                         {"hipdnnSetConvolutionMathType",                         CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetConvolutionMathType",                         {"hipdnnGetConvolutionMathType",                         CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSetConvolutionGroupCount",                       {"hipdnnSetConvolutionGroupCount",                       CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetConvolutionGroupCount",                       {"hipdnnGetConvolutionGroupCount",                       CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSetConvolution2dDescriptor",                     {"hipdnnSetConvolution2dDescriptor",                     CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetConvolution2dDescriptor",                     {"hipdnnGetConvolution2dDescriptor",                     CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetConvolution2dForwardOutputDim",               {"hipdnnGetConvolution2dForwardOutputDim",               CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetConvolutionNdDescriptor",                     {"hipdnnSetConvolutionNdDescriptor",                     CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetConvolutionNdDescriptor",                     {"hipdnnGetConvolutionNdDescriptor",                     CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetConvolutionNdForwardOutputDim",               {"hipdnnGetConvolutionNdForwardOutputDim",               CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnDestroyConvolutionDescriptor",                   {"hipdnnDestroyConvolutionDescriptor",                   CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetConvolutionForwardAlgorithmMaxCount",         {"hipdnnGetConvolutionForwardAlgorithmMaxCount",         CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnFindConvolutionForwardAlgorithm",                {"hipdnnFindConvolutionForwardAlgorithm",                CONV_MATH_FUNC, API_DNN}},
  {"cudnnFindConvolutionForwardAlgorithmEx",              {"hipdnnFindConvolutionForwardAlgorithmEx",              CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetConvolutionForwardAlgorithm",                 {"hipdnnGetConvolutionForwardAlgorithm",                 CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetConvolutionForwardAlgorithm_v7",              {"hipdnnGetConvolutionForwardAlgorithm_v7",              CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetConvolutionForwardWorkspaceSize",             {"hipdnnGetConvolutionForwardWorkspaceSize",             CONV_MATH_FUNC, API_DNN}},
  {"cudnnConvolutionForward",                             {"hipdnnConvolutionForward",                             CONV_MATH_FUNC, API_DNN}},
  {"cudnnConvolutionBiasActivationForward",               {"hipdnnConvolutionBiasActivationForward",               CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnConvolutionBackwardBias",                        {"hipdnnConvolutionBackwardBias",                        CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetConvolutionBackwardFilterAlgorithmMaxCount",  {"hipdnnGetConvolutionBackwardFilterAlgorithmMaxCount",  CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnFindConvolutionBackwardFilterAlgorithm",         {"hipdnnFindConvolutionBackwardFilterAlgorithm",         CONV_MATH_FUNC, API_DNN}},
  {"cudnnFindConvolutionBackwardFilterAlgorithmEx",       {"hipdnnFindConvolutionBackwardFilterAlgorithmEx",       CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetConvolutionBackwardFilterAlgorithm",          {"hipdnnGetConvolutionBackwardFilterAlgorithm",          CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetConvolutionBackwardFilterAlgorithm_v7",       {"hipdnnGetConvolutionBackwardFilterAlgorithm_v7",       CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetConvolutionBackwardFilterWorkspaceSize",      {"hipdnnGetConvolutionBackwardFilterWorkspaceSize",      CONV_MATH_FUNC, API_DNN}},
  {"cudnnConvolutionBackwardFilter",                      {"hipdnnConvolutionBackwardFilter",                      CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetConvolutionBackwardDataAlgorithmMaxCount",    {"hipdnnGetConvolutionBackwardDataAlgorithmMaxCount",    CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnFindConvolutionBackwardDataAlgorithm",           {"hipdnnFindConvolutionBackwardDataAlgorithm",           CONV_MATH_FUNC, API_DNN}},
  {"cudnnFindConvolutionBackwardDataAlgorithmEx",         {"hipdnnFindConvolutionBackwardDataAlgorithmEx",         CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetConvolutionBackwardDataAlgorithm",            {"hipdnnGetConvolutionBackwardDataAlgorithm",            CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetConvolutionBackwardDataAlgorithm_v7",         {"hipdnnGetConvolutionBackwardDataAlgorithm_v7",         CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetConvolutionBackwardDataWorkspaceSize",        {"hipdnnGetConvolutionBackwardDataWorkspaceSize",        CONV_MATH_FUNC, API_DNN}},
  {"cudnnConvolutionBackwardData",                        {"hipdnnConvolutionBackwardData",                        CONV_MATH_FUNC, API_DNN}},

  // cuDNN Sortmax functions
  {"cudnnSoftmaxForward",                                 {"hipdnnSoftmaxForward",                                 CONV_MATH_FUNC, API_DNN}},
  {"cudnnSoftmaxBackward",                                {"hipdnnSoftmaxBackward",                                CONV_MATH_FUNC, API_DNN}},

  // cuDNN Pooling functions
  {"cudnnCreatePoolingDescriptor",                        {"hipdnnCreatePoolingDescriptor",                        CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetPooling2dDescriptor",                         {"hipdnnSetPooling2dDescriptor",                         CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetPooling2dDescriptor",                         {"hipdnnGetPooling2dDescriptor",                         CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetPoolingNdDescriptor",                         {"hipdnnSetPoolingNdDescriptor",                         CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetPoolingNdDescriptor",                         {"hipdnnGetPoolingNdDescriptor",                         CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetPoolingNdForwardOutputDim",                   {"hipdnnGetPoolingNdForwardOutputDim",                   CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetPooling2dForwardOutputDim",                   {"hipdnnGetPooling2dForwardOutputDim",                   CONV_MATH_FUNC, API_DNN}},
  {"cudnnDestroyPoolingDescriptor",                       {"hipdnnDestroyPoolingDescriptor",                       CONV_MATH_FUNC, API_DNN}},
  {"cudnnPoolingForward",                                 {"hipdnnPoolingForward",                                 CONV_MATH_FUNC, API_DNN}},
  {"cudnnPoolingBackward",                                {"hipdnnPoolingBackward",                                CONV_MATH_FUNC, API_DNN}},

  // cuDNN Activation functions
  {"cudnnCreateActivationDescriptor",                     {"hipdnnCreateActivationDescriptor",                     CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetActivationDescriptor",                        {"hipdnnSetActivationDescriptor",                        CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetActivationDescriptor",                        {"hipdnnGetActivationDescriptor",                        CONV_MATH_FUNC, API_DNN}},
  {"cudnnDestroyActivationDescriptor",                    {"hipdnnDestroyActivationDescriptor",                    CONV_MATH_FUNC, API_DNN}},
  {"cudnnActivationForward",                              {"hipdnnActivationForward",                              CONV_MATH_FUNC, API_DNN}},
  {"cudnnActivationBackward",                             {"hipdnnActivationBackward",                             CONV_MATH_FUNC, API_DNN}},

  // cuDNN LRN functions
  {"cudnnCreateLRNDescriptor",                            {"hipdnnCreateLRNDescriptor",                            CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetLRNDescriptor",                               {"hipdnnSetLRNDescriptor",                               CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetLRNDescriptor",                               {"hipdnnGetLRNDescriptor",                               CONV_MATH_FUNC, API_DNN}},
  {"cudnnDestroyLRNDescriptor",                           {"hipdnnDestroyLRNDescriptor",                           CONV_MATH_FUNC, API_DNN}},
  {"cudnnLRNCrossChannelForward",                         {"hipdnnLRNCrossChannelForward",                         CONV_MATH_FUNC, API_DNN}},
  {"cudnnLRNCrossChannelBackward",                        {"hipdnnLRNCrossChannelBackward",                        CONV_MATH_FUNC, API_DNN}},

  // cuDNN Divisive Normalization functions
  {"cudnnDivisiveNormalizationForward",                   {"hipdnnDivisiveNormalizationForward",                   CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnDivisiveNormalizationBackward",                  {"hipdnnDivisiveNormalizationBackward",                  CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},

  // cuDNN Batch Normalization functions
  {"cudnnDeriveBNTensorDescriptor",                       {"hipdnnDeriveBNTensorDescriptor",                       CONV_MATH_FUNC, API_DNN}},
  {"cudnnBatchNormalizationForwardTraining",              {"hipdnnBatchNormalizationForwardTraining",              CONV_MATH_FUNC, API_DNN}},
  {"cudnnBatchNormalizationForwardInference",             {"hipdnnBatchNormalizationForwardInference",             CONV_MATH_FUNC, API_DNN}},
  {"cudnnBatchNormalizationBackward",                     {"hipdnnBatchNormalizationBackward",                     CONV_MATH_FUNC, API_DNN}},

  // cuDNN Spatial Transformer functions
  {"cudnnCreateSpatialTransformerDescriptor",             {"hipdnnCreateSpatialTransformerDescriptor",             CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSetSpatialTransformerNdDescriptor",              {"hipdnnSetSpatialTransformerNdDescriptor",              CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnDestroySpatialTransformerDescriptor",            {"hipdnnDestroySpatialTransformerDescriptor",            CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSpatialTfGridGeneratorForward",                  {"hipdnnSpatialTfGridGeneratorForward",                  CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSpatialTfGridGeneratorBackward",                 {"hipdnnSpatialTfGridGeneratorBackward",                 CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSpatialTfSamplerForward",                        {"hipdnnSpatialTfSamplerForward",                        CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSpatialTfSamplerBackward",                       {"hipdnnSpatialTfSamplerBackward",                       CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},

  // cuDNN Dropout functions
  {"cudnnCreateDropoutDescriptor",                        {"hipdnnCreateDropoutDescriptor",                        CONV_MATH_FUNC, API_DNN}},
  {"cudnnDestroyDropoutDescriptor",                       {"hipdnnDestroyDropoutDescriptor",                       CONV_MATH_FUNC, API_DNN}},
  {"cudnnDropoutGetStatesSize",                           {"hipdnnDropoutGetStatesSize",                           CONV_MATH_FUNC, API_DNN}},
  {"cudnnDropoutGetReserveSpaceSize",                     {"hipdnnDropoutGetReserveSpaceSize",                     CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSetDropoutDescriptor",                           {"hipdnnSetDropoutDescriptor",                           CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetDropoutDescriptor",                           {"hipdnnGetDropoutDescriptor",                           CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnRestoreDropoutDescriptor",                       {"hipdnnRestoreDropoutDescriptor",                       CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnDropoutForward",                                 {"hipdnnDropoutForward",                                 CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnDropoutBackward",                                {"hipdnnDropoutBackward",                                CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},

  // cuDNN RNN functions
  {"cudnnCreateRNNDescriptor",                            {"hipdnnCreateRNNDescriptor",                            CONV_MATH_FUNC, API_DNN}},
  {"cudnnDestroyRNNDescriptor",                           {"hipdnnDestroyRNNDescriptor",                           CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetRNNForwardInferenceAlgorithmMaxCount",        {"hipdnnGetRNNForwardInferenceAlgorithmMaxCount",        CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnFindRNNForwardInferenceAlgorithmEx",             {"hipdnnFindRNNForwardInferenceAlgorithmEx",             CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetRNNForwardTrainingAlgorithmMaxCount",         {"hipdnnGetRNNForwardTrainingAlgorithmMaxCount",         CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnFindRNNForwardTrainingAlgorithmEx",              {"hipdnnFindRNNForwardTrainingAlgorithmEx",              CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetRNNBackwardDataAlgorithmMaxCount",            {"hipdnnGetRNNBackwardDataAlgorithmMaxCount",            CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnFindRNNBackwardDataAlgorithmEx",                 {"hipdnnFindRNNBackwardDataAlgorithmEx",                 CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetRNNBackwardWeightsAlgorithmMaxCount",         {"hipdnnGetRNNBackwardWeightsAlgorithmMaxCount",         CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnFindRNNBackwardWeightsAlgorithmEx",              {"hipdnnFindRNNBackwardWeightsAlgorithmEx",              CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnCreatePersistentRNNPlan",                        {"hipdnnCreatePersistentRNNPlan",                        CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetPersistentRNNPlan",                           {"hipdnnSetPersistentRNNPlan",                           CONV_MATH_FUNC, API_DNN}},
  {"cudnnDestroyPersistentRNNPlan",                       {"hipdnnDestroyPersistentRNNPlan",                       CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetRNNDescriptor",                               {"hipdnnSetRNNDescriptor",                               CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetRNNDescriptor",                               {"hipdnnGetRNNDescriptor",                               CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSetRNNProjectionLayers",                         {"hipdnnSetRNNProjectionLayers",                         CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetRNNProjectionLayers",                         {"hipdnnGetRNNProjectionLayers",                         CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSetRNNAlgorithmDescriptor",                      {"hipdnnSetRNNAlgorithmDescriptor",                      CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSetRNNMatrixMathType",                           {"hipdnnSetRNNMatrixMathType",                           CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetRNNMatrixMathType",                           {"hipdnnGetRNNMatrixMathType",                           CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetRNNWorkspaceSize",                            {"hipdnnGetRNNWorkspaceSize",                            CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetRNNTrainingReserveSize",                      {"hipdnnGetRNNTrainingReserveSize",                      CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetRNNParamsSize",                               {"hipdnnGetRNNParamsSize",                               CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetRNNLinLayerMatrixParams",                     {"hipdnnGetRNNLinLayerMatrixParams",                     CONV_MATH_FUNC, API_DNN}},
  {"cudnnGetRNNLinLayerBiasParams",                       {"hipdnnGetRNNLinLayerBiasParams",                       CONV_MATH_FUNC, API_DNN}},
  {"cudnnRNNForwardInference",                            {"hipdnnRNNForwardInference",                            CONV_MATH_FUNC, API_DNN}},
  {"cudnnRNNForwardTraining",                             {"hipdnnRNNForwardTraining",                             CONV_MATH_FUNC, API_DNN}},
  {"cudnnRNNBackwardData",                                {"hipdnnRNNBackwardData",                                CONV_MATH_FUNC, API_DNN}},
  {"cudnnRNNBackwardWeights",                             {"hipdnnRNNBackwardWeights",                             CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetRNNDescriptor_v5",                            {"hipdnnSetRNNDescriptor_v5",                            CONV_MATH_FUNC, API_DNN}},
  {"cudnnSetRNNDescriptor_v6",                            {"hipdnnSetRNNDescriptor_v6",                            CONV_MATH_FUNC, API_DNN}},

  // cuDNN Connectionist Temporal Classification loss functions
  {"cudnnCreateCTCLossDescriptor",                        {"hipdnnCreateCTCLossDescriptor",                        CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSetCTCLossDescriptor",                           {"hipdnnSetCTCLossDescriptor",                           CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetCTCLossDescriptor",                           {"hipdnnGetCTCLossDescriptor",                           CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnDestroyCTCLossDescriptor",                       {"hipdnnDestroyCTCLossDescriptor",                       CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnCTCLoss",                                        {"hipdnnCTCLoss",                                        CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetCTCLossWorkspaceSize",                        {"hipdnnGetCTCLossWorkspaceSize",                        CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},

  // cuDNN Algorithm functions
  {"cudnnCreateAlgorithmDescriptor",                      {"hipdnnCreateAlgorithmDescriptor",                      CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSetAlgorithmDescriptor",                         {"hipdnnSetAlgorithmDescriptor",                         CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetAlgorithmDescriptor",                         {"hipdnnGetAlgorithmDescriptor",                         CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnCopyAlgorithmDescriptor",                        {"hipdnnCopyAlgorithmDescriptor",                        CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnDestroyAlgorithmDescriptor",                     {"hipdnnDestroyAlgorithmDescriptor",                     CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnCreateAlgorithmPerformance",                     {"hipdnnCreateAlgorithmPerformance",                     CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSetAlgorithmPerformance",                        {"hipdnnSetAlgorithmPerformance",                        CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetAlgorithmPerformance",                        {"hipdnnGetAlgorithmPerformance",                        CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnDestroyAlgorithmPerformance",                    {"hipdnnDestroyAlgorithmPerformance",                    CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnGetAlgorithmSpaceSize",                          {"hipdnnGetAlgorithmSpaceSize",                          CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnSaveAlgorithm",                                  {"hipdnnSaveAlgorithm",                                  CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
  {"cudnnRestoreAlgorithm",                               {"hipdnnRestoreAlgorithm",                               CONV_MATH_FUNC, API_DNN, HIP_UNSUPPORTED}},
};

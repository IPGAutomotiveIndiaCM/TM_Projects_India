/***************************************************** target specific file ***/
/*  Wrapper module for Simulink models                                        */
/*  ------------------------------------------------------------------------  */
/*  (c) IPG Automotive GmbH    www.ipg-automotive.com   Fon: +49.721.98520-0  */
/*  Bannwaldallee 60      D-76185 Karlsruhe   Germany   Fax: +49.721.98520-99 */
/******************************************************************************/

#ifndef __SWITCHMOBILITY_ACC_WRAP_H__
#define __SWITCHMOBILITY_ACC_WRAP_H__

#ifndef IS_TRUCK
# define IS_TRUCK
#endif

#ifdef __cplusplus
extern "C" {
#endif


struct tInfos;
struct tMdlBdyFrame;
struct tMatSuppDictDef;
struct tMatSuppTunables;


#ifdef CLASSIC_INTERFACE
# define rtModel_SwitchMobility_ACC          RT_MODEL_SwitchMobility_ACC_T
#else
# define rtModel_SwitchMobility_ACC          tag_RTM_SwitchMobility_ACC_T
#endif //CLASSIC_INTERFACE

#define ExternalInputs_SwitchMobility_ACC   ExtU_SwitchMobility_ACC_T
#define ExternalOutputs_SwitchMobility_ACC  ExtY_SwitchMobility_ACC_T

#ifndef SwitchMobility_ACC_rtModel
typedef struct rtModel_SwitchMobility_ACC rtModel_SwitchMobility_ACC;
#endif

/* Model registration function */
rtModel_SwitchMobility_ACC *SwitchMobility_ACC (struct tInfos *Inf);

#if defined(CLASSIC_INTERFACE) && !defined(CM4SLDS)
void rt_ODECreateIntegrationData (RTWSolverInfo *si);
void rt_ODEUpdateContinuousStates(RTWSolverInfo *si);
void rt_ODEDestroyIntegrationData(RTWSolverInfo *si);
#endif


/* Dictionary variables and other items of the model */
extern struct tMatSuppDictDef *SwitchMobility_ACC_DictDefines;
extern struct tMdlBdyFrame *SwitchMobility_ACC_BdyFrameDefines;


/* Wrapper functions */
void SwitchMobility_ACC_SetParams (rtModel_SwitchMobility_ACC *rtm,
			struct tMatSuppTunables *tuns,
			struct tInfos *Inf);
int SwitchMobility_ACC_Register (void);


#ifdef __cplusplus
}
#endif

#endif /* __SWITCHMOBILITY_ACC_WRAP_H__ */


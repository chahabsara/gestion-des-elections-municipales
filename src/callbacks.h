#include <gtk/gtk.h>


void
on_login_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_create_account_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_cancel_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_save_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_delete_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_bv3_group_changed                   (GtkRadioButton  *radiobutton,
                                        gpointer         user_data);

void
on_bv2_group_changed                   (GtkRadioButton  *radiobutton,
                                        gpointer         user_data);

void
on_bv1_group_changed                   (GtkRadioButton  *radiobutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_exit1_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_exit0_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_exit2_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_voter_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_arriere_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton3_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton11_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2_group_changed          (GtkRadioButton  *radiobutton,
                                        gpointer         user_data);

void
on_radiobutton3_group_changed          (GtkRadioButton  *radiobutton,
                                        gpointer         user_data);

void
on_deleteUser_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifyUser_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_displayUser_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_addUser_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_exit3_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_exit4_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_delete_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_exit5_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_modify_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_stat_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_delete_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_exit6_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_getBack_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_exit6_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_getBack_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_search_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_clear_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_AllerMenuChoix_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewRecla_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_NombreReclamationparl_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_refreshTreeRecl_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_SuprimerAffichageRec_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_ModifierAffichageRec_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_AjouterAffichageRec_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_exitGesRecla_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confirmAjoutRec_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_RetourAjoutRec_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rechercherReclamation_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton_homme_modif_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_modif_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkModif_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confirmModifRec_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ReturnModifRec_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_RetourSupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirmersupp_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirmNombreRec_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ReturnNbreAffichage_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_OKNbreReclam_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_AllerReclamation_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_ExitChoix_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_RetourChoix_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_RetourMenuRec_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_th_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_modif_aff_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_sup_aff_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_act_aff_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_dec_aff__clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ajout_aff_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_confirm_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_supp_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_recherche_id_modif_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ariana_modif_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_tunis_modif_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton11_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confirm_modif1_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_modif_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ariana_aj_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Tunis_ajj_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton11_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_confirm_ajj_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_ajj_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_checkbutton111_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton22_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_th_clicked                          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview_th_row_activated           (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_modif_aff1_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_voterSH_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_LcondidatSH_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_statSarra_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_afficheGrapheSarra_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimerfer_clicked         (GtkButton       *objet,
                                        gpointer         user_data);



void
on_button_chercherfer_clicked          (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_afficherfer_clicked          (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_ajouterfer_clicked           (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_suppferr_clicked             (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_button13fer_clicked                 (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button17fer_clicked                 (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_confirmerfer_clicked         (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_checkbutton_firas_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1fer_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2fer_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3fer_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_dfer_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button16fer_clicked                 (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button14fer_clicked                 (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button15fer_clicked                 (GtkButton       *objet,
                                        gpointer         user_data);

void
on_radiobutton4fer_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton6fer_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton5fer_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeviewfer_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button11fer_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12fer_clicked                 (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button_modifer_clicked              (GtkButton       *button,
                                        gpointer         user_data);



void
on_button_modifierfer_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_bureauV_clicked                     (GtkButton       *objet,
                                        gpointer         user_data);

void
on_suppch_clicked                      (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_modifch_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data);


void
on_ajoutch_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_refch_clicked                       (GtkButton       *objet,
                                        gpointer         user_data);

void
on_closech_clicked                     (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_radiobutton2ch_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confirch_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_hom1ch_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_hom2ch_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_confir_modifch_clicked              (GtkButton       *objet,
                                        gpointer         user_data);

void
on_cherchch_clicked                    (GtkButton       *objet,
                                        gpointer         user_data);

void
on_confir_suppch_clicked               (GtkButton       *objet,
                                        gpointer         user_data);

void
on_hom3ch_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1ch_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_entrerch_clicked                    (GtkButton       *objet,
                                        gpointer         user_data);

void
on_radiobutton1ch_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_trv_row_activated                   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ch_clicked                          (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkAjout_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_okDialogSupp_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_triNomReclm_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_toRechReclama_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourRechCritere_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_radioCrit1_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radioCriter2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_afficherCritere_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_chercher_mm8_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_mm3_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_mm2_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_lolm6_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_actualiser_olm10_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_mm2_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_mmp5_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_ajouter_obs_mm24_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_verifier_m_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_mmpp_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_mmhh_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_mm102_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_modifier_obs_mm41_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_aff_mm26_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_aff_demodif_mm32_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_he_clicked                          (GtkButton       *button,
                                        gpointer         user_data);

void
on_score_condidats_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_tauxPartEtDeVote_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonExitPageStatSarra_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_returnPageStatSarra_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficheStatScore_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficherDiagVote_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonExitTreeViewStatVote_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_annulerStatVote_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_exitStatScoreTreeView_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_annulercondidatTreeView_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_Retourfirace_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_exithadil_clicked                   (GtkButton       *button,
                                        gpointer         user_data);
